// ==UserScript==
// @name         萌娘百科跳转镜像网站
// @version      1.0
// @description  在访问主站时自动跳转到镜像网站:'moegirl.uk'
// @match        https://mzh.moegirl.org.cn/*
// @match        https://zh.moegirl.org.cn/*
// @license      MIT
// @grant        none
// @run-at       document-start
// @namespace    http://tampermonkey.net/
// ==/UserScript==

const uk = new URL(window.location.href);
uk.host = "moegirl.uk";
// remove language /zh-Hans/ if exists
const a = uk.pathname.slice(1);
const b = a.indexOf("/");
if (b > -1) {
  uk.pathname = a.slice(b);
}
// go!
window.location = uk.href;
