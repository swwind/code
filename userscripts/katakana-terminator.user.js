// ==UserScript==
// @name         片假名终结者
// @namespace    http://tampermonkey.net/
// @version      2024-08-03
// @description  消灭片假名！
// @author       You
// @match        *://*/*
// @icon         data:image/gif;base64,R0lGODlhAQABAAAAACH5BAEKAAEALAAAAAABAAEAAAICTAEAOw==
// @grant        none
// ==/UserScript==

/** @type {Map<string, Node[]>} */
const queue = new Map();
/** @type {Map<string, string>} */
const dictionary = new Map();

// Recursively traverse the given node and its descendants (Depth-first search)
function scanTextNodes(node) {
  // The node could have been detached from the DOM tree
  if (!node.parentNode || !document.body.contains(node)) {
    return;
  }

  // Ignore text boxes and echoes
  const excludeTags = ["ruby", "script", "select", "textarea"];

  switch (node.nodeType) {
    case Node.ELEMENT_NODE:
      if (
        excludeTags.includes(node.tagName.toLowerCase()) ||
        node.isContentEditable
      ) {
        return;
      }
      return Array.from(node.childNodes).forEach(scanTextNodes);

    case Node.TEXT_NODE:
      while ((node = addRuby(node)));
  }
}

const katakana =
  /[\u30A1-\u30FA\u30FD-\u30FF][\u3099\u309A\u30A1-\u30FF]*[\u3099\u309A\u30A1-\u30FA\u30FC-\u30FF]|[\uFF66-\uFF6F\uFF71-\uFF9D][\uFF65-\uFF9F]*[\uFF66-\uFF9F]/;

// Recursively add ruby tags to text nodes
// Inspired by http://www.the-art-of-web.com/javascript/search-highlight/
/**
 * @param {Text} node
 */
function addRuby(node) {
  let match;
  if (!node.nodeValue || !(match = katakana.exec(node.nodeValue))) {
    return false;
  }
  const ja = match[0];

  const ruby = document.createElement("ruby");
  // ruby.style.background = 'rgba(184, 224, 212, 0.25)'
  ruby.appendChild(document.createTextNode(ja));
  const rt = document.createElement("rt");
  rt.classList.add("katakana-terminator-rt");
  rt.style.fontSize = "1em";
  ruby.appendChild(rt);

  // Append the ruby title node to the pending-translation queue
  if (!queue.has(ja)) queue.set(ja, []);
  queue.get(ja).push(rt);

  // <span>[startカナmiddleテストend]</span> =>
  // <span>start<ruby>カナ<rt data-rt="Kana"></rt></ruby>[middleテストend]</span>
  const after = node.splitText(match.index);
  node.parentNode.insertBefore(ruby, after);
  after.nodeValue = after.nodeValue.slice(ja.length);
  return after;
}

// Split word list into chunks to limit the length of API requests
function translateTextNodes() {
  /** @type {string[]} */
  const words = [];

  for (const word of queue.keys()) {
    if (dictionary.has(word)) {
      updateRuby(word);
      continue;
    }

    words.push(word);

    if (words.length === 50) {
      translate(words);
      words.length = 0;
    }
  }

  if (words.length > 0) {
    translate(words);
  }
}

const GOOGLE_TRANSLATE =
  "https://translate.googleapis.com/translate_a/single?sl=ja&tl=en&dt=t&client=gtx";

/**
 * @param {string[]} phrases
 */
function translate(phrases) {
  const url = new URL(GOOGLE_TRANSLATE);
  url.searchParams.set("q", phrases.join("\n"));

  fetch(url)
    .then((res) => res.json())
    .then((res) => {
      for (const trans of res[0]) {
        const en = trans[0].trimEnd();
        const ja = trans[1].trimEnd();
        dictionary.set(ja, en);
        updateRuby(ja);
      }
    });
}

// Clear the pending-translation queue
/**
 *
 * @param {string} phrase
 */
function updateRuby(phrase) {
  const en = dictionary.get(phrase);
  const nodes = queue.get(phrase);
  if (nodes) {
    for (const node of nodes) {
      node.dataset.rt = en;
    }
    queue.delete(phrase);
  }
}

function main() {
  mountStyle("rt.katakana-terminator-rt::before { content: attr(data-rt); }");

  /**
   * @param {Node[]} nodes
   */
  const updateNodes = (nodes) => {
    // if no new node add
    if (!nodes.length) return;

    for (const node of nodes) {
      scanTextNodes(node);
    }
    translateTextNodes();
  };

  /** @type {Node[]} */
  const cache = [];

  /**
   * @param {MutationRecord[]} mutationList
   */
  const callback = (mutationList) => {
    cache.push(...mutationList.flatMap((x) => Array.from(x.addedNodes)));
  };

  const observer = new MutationObserver(callback);
  observer.observe(document.body, { childList: true, subtree: true });

  updateNodes([document.body]);

  // Limit the frequency of API requests
  setInterval(() => {
    const nodes = [...cache];
    cache.length = 0;
    updateNodes(nodes);
  }, 1000);
}

/**
 * @param {string} css
 */
function mountStyle(css) {
  const style = document.createElement("style");
  style.setAttribute("type", "text/css");
  style.textContent = css;
  document.head.appendChild(style);
}

let start = false;

addEventListener("keydown", (e) => {
  if (!start && e.altKey && e.key === "k") {
    start = true;
    main();
  }
});
