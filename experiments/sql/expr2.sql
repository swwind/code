-- 1. 查询选了 1 号课且选了 2 号课的学生的班号、学号
select sclass, sno
from sc as a
where a.cno = 1
  and exists (
    select *
    from sc as b
    where b.sclass = a.sclass
      and b.sno = a.sno
      and b.cno = 2
  );

-- 2. 查询选了 1 号课但不选 2 号课的学生的班号、学号
select sclass, sno
from sc as a
where a.cno = 1
  and not exists (
    select *
    from sc as b
    where b.sclass = a.sclass
      and b.sno = a.sno
      and b.cno = 2
  );

-- 3. 查询 1 班平均分在 85 分以上的同学班号、学号、姓名、性别、系、各科课程号及成绩
select s.sclass, s.sno, sname, ssex, sdept, cno, grade
from s, sc
where sc.sclass = s.sclass
  and sc.sno = s.sno
  and (s.sclass, s.sno) in (
    select sclass, sno
    from sc
    where sclass = 1
    group by (sclass, sno)
    having avg(grade) > 85
  );

-- 4. 查询至少选了 1 班 2 号同学所选课的所有班号、学号及同学姓名
select sclass, sno, sname
from s
where sno in (
  select sno
  from sc
  where cno in (
    select cno
    from sc
    where sclass = 1
      and sno = 2
  )
);

-- 5. 查询不选1号课的学生班号及学号
select sclass, sno
from s
where not exists (
  select *
  from sc
  where s.sclass = sc.sclass
    and s.sno = sc.sno
    and cno = 1
);

-- 6. 查询选 2 号课的学生名字及相应 2 号课成绩，按成绩从高到低排序
select sname, grade
from s, sc
where s.sclass = sc.sclass
  and s.sno = sc.sno
  and cno = 2
order by grade desc;

-- 7. 统计学生选修课程的班号、学号及总学分
select sclass, sno, sum(ccredit)
from sc, c
where sc.cno = c.cno
group by (sclass, sno);

-- 8. 统计 1 班选修 3 号课的学号及平均分
select sno
from sc
where sclass = 1
  and cno = 3;

select avg(grade)
from sc
where sclass = 1
  and cno = 3;

-- 9. 把个人信息及选课信息插入到 Student 和 SC 表及新增加一门“无机化学”课程信息
insert into s
values (1, 4, '陈睿', '男', 44, 'IS');

insert into c
values (8, '无机化学', null, 5);

insert into sc
values
  (1, 1, 8, 99),
  (1, 4, 8, 59),
  (2, 1, 8, 98);

-- 10. 删除选修 3 号课的所有选课信息并显示删除后的结果
delete
from sc
where cno = 3;

select * from sc;

-- 11. 把选修 1 号课的所有男同学年龄增加 1 岁并显示最终学生 Student 信息
update s
set sage = sage + 1
where ssex = '男'
  and (sclass, sno) in (
    select sclass, sno
    from sc
    where cno = 1
  );

select * from s;

-- 12. 把每个选课人的学号、班号及平均成绩插入到一个新表中。
create table if not exists sclass_sno_avg_grade (
  sclass int not null,
  sno int not null,
  avg_grade float not null,
  primary key (sclass, sno),
  foreign key (sclass, sno) references s(sclass, sno)
);

insert into sclass_sno_avg_grade
select sclass, sno, avg(grade)
from sc
group by (sclass, sno);

-- 1. 在 ST 库中以“student”表为基础，建立信息系学生的视图 V_IS_Student
create view V_IS_Student as
select *
from s
where sdept = 'IS';

-- 2.1. 建立一个每个学生的学号、班号、姓名、选修的课名及成绩的视图 S_C_GRADE；
create view S_C_GRADE as
select s.sno, s.sclass, sname, cname, grade
from s, sc, c
where s.sclass = sc.sclass
  and s.sno = sc.sno
  and c.cno = sc.cno;

-- 2.2. 建立信息系建立信息系选修了 1 号课程且成绩在 90 分以上的学生的视图 V_IS_Score
create view V_IS_Score as
select *
from s
where (sclass, sno) in (
  select sclass, sno
  from sc
  where cno = 1
    and grade >= 90
);

-- 2.3. 将各系学生人数，平均年龄定义为视图 V_NUM_AVG。
create view V_NUM_AVG as
select sdept, count(*), avg(sage)
from s
group by sdept;

-- 3. 查询以上所建的视图结果
select * from V_IS_Student;
select * from S_C_GRADE;
select * from V_IS_Score;
select * from V_NUM_AVG;

-- 4. 查询选修了 1 号课程的信息系学生
select *
from V_IS_Student as s
where exists (
  select *
  from sc
  where sc.sclass = s.sclass
    and sc.sno = s.sno
    and cno = 1
);

-- 5. 在信息系学生的视图中找出年龄小于 20 岁的学生
select *
from V_IS_Student
where sage < 20;

-- 6. 将信息系学生视图 V_IS_Student 中学号一班 2 号的学生姓名改为“刘辰”

-- update V_IS_Student
-- set sname = '刘辰'
-- where sclass = 1
--   and sno = 2;

-- ERROR:  cannot update view "v_is_student"
-- HINT:  You need an unconditional ON UPDATE DO INSTEAD rule or an INSTEAD OF UPDATE trigger.

update s
set sname = '刘辰'
where sclass = 1
  and sno = 2
  and (sclass, sno) in (
    select sclass, sno
    from V_IS_Student
  );

-- 7. 用 SQL 语句删除视图 S_C_GRADE
drop view S_C_GRADE;
