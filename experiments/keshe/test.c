/* Processed by ecpg (14.3) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "test.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* exec sql begin declare section */
 
     

#line 6 "test.pgc"
 int var_c1 ;
 
#line 7 "test.pgc"
 char var_c2 [ 21 ] = { 0x00 } ;
/* exec sql end declare section */
#line 8 "test.pgc"


int main(int argc, char* argv[])
{
  /* 步骤1: 建立连接 */
  /* exec sql whenever sqlerror  sqlprint ; */
#line 13 "test.pgc"
   /* 声明异常发生时的处理动作统一为打印消息 */
  { ECPGconnect(__LINE__, 0, "postgres@localhost:5432" , "postgres" , "xxxx" , NULL, 0); 
#line 14 "test.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 14 "test.pgc"
   /* 指定连接的目标据库，用户名，密码 */  

  /* 步骤2: 利用游标执行查询 */
  /* declare foo_bar cursor for select c1 , c2 from tb1 */
#line 17 "test.pgc"
    /* 声明一个游标使之用于执行SELECT文 */
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare foo_bar cursor for select c1 , c2 from tb1", ECPGt_EOIT, ECPGt_EORT);
#line 18 "test.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 18 "test.pgc"
                                         /* 打开游标从而使SELECT文被执行 */
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch foo_bar", ECPGt_EOIT, 
	ECPGt_int,&(var_c1),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(var_c2),(long)21,(long)1,(21)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 19 "test.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 19 "test.pgc"
                  /* 获取一行数据 */

  printf("C1: %d, C2: %s\n", var_c1, var_c2);

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close foo_bar", ECPGt_EOIT, ECPGt_EORT);
#line 23 "test.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 23 "test.pgc"
                                        /* 关闭所打开的游标 */

  /* 步骤3: 关闭连接 */
  { ECPGdisconnect(__LINE__, "CURRENT");
#line 26 "test.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 26 "test.pgc"


  return 0;
}