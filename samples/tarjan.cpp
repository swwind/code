// tarjan

int dfn[N], low[N], que[N], blo[N], qnt, bnt, tot, sz[N];
void tarjan(int x) {
  dfn[x] = low[x] = ++ tot;
  que[++ qnt] = x;
  for (int i = head[x]; i; i = nxt[i])
    if (!dfn[to[i]]) tarjan(to[i]), low[x] = min(low[x], low[to[i]]);
    else if (!blo[to[i]]) low[x] = min(low[x], dfn[to[i]]);
  if (dfn[x] == low[x] && ++ bnt)
    while (que[qnt + 1] != x)
      blo[que[qnt --]] = bnt, sz[bnt] ++;
}