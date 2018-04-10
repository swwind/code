// 在 bzoj 注册页面打开 f12 控制台粘贴以下内容即可
$('#register-button').unbind('click').click(function () {
  var e = $(O).data("ticket"),
    t = _($(".register-form"));
  t.timestamp = (new Date).getTime(), t.requestId = e;
  var n = JSON.stringify(t), i = D(n);
  $.ajax({
    url: "/register",
    type: "POST",
    async: !0,
    contentType: "application/json",
    data: n,
    dataType: "json",
    beforeSend: function(e) {
      e.setRequestHeader("X-CONTENT-HASH", i)
    },
    success: function(e) {
      if (null == e.code) Materialize.toast("500错误:服务器出错，请联系管理员", 2e3);
      else if (200 != e.code) Materialize.toast(e.code + "错误：" + e.message, 2e3);
      else {
        $("#register-button").addClass("disabled"), Materialize.toast("注册成功，即将跳转回首页", 2e3), setTimeout(function() {
          window.location.href = "/"
        }, 2e3)
      }
    }
  })
})