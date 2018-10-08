'use strict';

const read = require('read');
const md5 = require('blueimp-md5');

const hash = (str, key, times) => {
  return times ? hash(md5(str + key), str, times - 1) : str;
}

const queryPassword = (prompt, silent = true) => new Promise((resolve, reject) => {
  read({ prompt, silent, terminal: true }, (er, password) => {
    resolve(password);
  });
});

const btoa = (str) => {
  return Buffer.from(str).toString('base64');
}

const generate = async () => {
  const str1 = await queryPassword('Password#1: ');
  const str2 = await queryPassword('Password#2: ');
  const str3 = await queryPassword('Password#3: ');

  const type = await queryPassword('Website: ', false);

  const h1 = hash(str1, str2, 10);
  const h2 = hash(str2, str3, 10);
  const h3 = hash(str3, str1, 10);

  const h4 = hash(str1, str3, 10);
  const h5 = hash(str2, str1, 10);
  const h6 = hash(str3, str2, 10);

  const r1 = hash(md5(h1 + h2 + h3), type, 10);
  const r2 = hash(md5(h4 + h5 + h6), type, 10);

  console.log(btoa(hash(r1, r2, 10)).slice(0, 16));

  process.exit(0);
}

generate();
