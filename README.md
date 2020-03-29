# Programming Contest Practice

過去問を埋めています.

problems: https://kenkoooo.com/atcoder/#/user/optie
graph: http://atcoder-scores.herokuapp.com/graph?user=optie

## Other Contest

- diverta2019_2_b: Picking Up. 「ある定数 p,q をもとに操作をした際のコストの最小値」→p, q が決まったと仮定してコストの最小値はどう求められるか、を考える.
- panasonic_b: 制約の下方のコーナーケースに注意
- panasonic_c:
  - boost::multiprecision を使う
  - long double を使い, =を<と判定されないように eps を足して`sqrt(a) + aqrt(b) + eps < sqrt(c)` とする
  - 整数化
    - `sqrt(a) + sqrt(b) < sqrt(c)`
    - <=> `a+b+2*sqrt(a*b) < c`
    - <=> `4*a*b < (c-a-b)^2` かつ `c-a-b>0`

## ARC

- arc004_2: 2 点間距離の最大と最小. 最小値は, 2 回まで適当な点で折ることを考えると、`d_max - (d_sum - d_max)` と 0 のうち大きい方が答えとなる

## ABC
- abc160_d: X-Yを通らないパタン、i→X→Y→j、i→Y→X→j にわけて考えると、`|i-j|` か `|X-i| + 1 + |j-Y|` か `|Y-i| + 1 + |X-j|` のどれかしかないことがわかる
- abc159_b: **変数の再代入に気をつける**
- abc159_e: 縦にだけ切るのだったら貪欲的に「K を超えないギリギリで切る」ので正解にたどり着ける. 縦幅の制約が小さいので、それぞれの隙間で横に切るかどうかで bit 全探索. 小さい制約を見たら bit 全探索を考えるのは有効か. 入力が数字の列であって空白区切りでない形だった場合、そのままループを回して受け取ってもだめなので、char で受け取るなどする.
- abc158_e: 10 進数の数は各桁を 10 べきの係数とみなすことで和で表現できる。それを割ったあまりは各 10 べき項の割ったあまりの和から考えられる。あとは累積和を考える。累積和の差分で区間を考えるとき、最小元を含む区間の表現は片方が配列外でないといけない（1-origin で a_k - a_0）ので、小さい方の値として 0 を含めておく必要がある
- abc157_c: 0 は一桁の整数に含まれる
- abc157_d: UnionFind で連結成分の要素数をカウントできる
- abc157_e: segment tree に集合を入れたくなったら bit で持てないか考える. アルファベットなら int bit に収まる. bit なら和集合も or を取るだけ.
- abc156_d: mod 減算でマイナスになったら mod を足す
- abc156_e: 0 人部屋がいくつあるかに応じて、重複組合せ `n H k = n+k-1 C k`
- abc155_D: 二分探索をする. そのために、 「ペアの積の小さい方から k 番目の値」は「x 未満になる値が k 個未満であるような x の最大値」と言い換える（k-1 個などとジャスト指定しないのは, 同じ数が続いたときなどに外してしまうので） . -INF:ok / INF: ng なので, その間を探す. そのために、「x を決めたときに、積が x 以下になるようなペアの数を数えて, k 個未満かどうかを返す」評価関数を設計したい. → ある数を固定して、相方を探して重複を外す.
- abc155_e: 支払う金額の決まった桁数と繰り下がりの有無を状態に持つ桁 DP. `dp[i][j]` 下から i 桁目まで決めて, 繰り下がりが j:0/1 のときの支払う紙幣の合計最小値. また, ある桁での払い方は「s 枚ピッタリ払う（=繰り下がり発生させず）」か「0 にして次の桁にまかせる（=繰り下がって,お釣りが 10-s 枚発生する）」かの二通りしかない
- abc154_e: **桁 DP** 「N より小さい整数」を列挙したいとき, 基本的には各桁を任意に選べるが, N と i 桁目まで一致している場合は選べるパタンが限られる. そこで, `dp[i][j]` i 桁目までが確定しているとき, j:N より小さいことが確定しているかどうか というテーブルを作って計算する. 今回は「残りの非ゼロ数」という状態を付け加える. また, N より小さいことが確定した瞬間に、非ゼロ残数 k に対して nCk \* 9^k を返すようにすると高速.
- abc154_f: まず一例として, パスカルの三角形とみなせる. 三角形としたときの行和は 2 の冪で, ある要素は nCk で求まる. また (1,1) からの和として考えると, (i,k) までの経路数は, (i-1, k=1..k) の累積和に等しい. さらにここから, (1,1)から(i,k)までの経路の総和は(i+1,k+1)-1 であることもわかる. これを利用すると簡単に求まる. nCk の高速計算についてチェックしておく
- abc153_e: ナップザック DP
- abc153_f: 貪欲でも良いがそのままでは間に合わない. 爆風の影響にある敵の体力をひとつずつ引いていく(N\*\*2 になりうる)のではなく Queue で区間を記憶しておく. vector(N) で初期化するときは容量ジャストにする. ソートするときに 0 初期化された領域まで含んでしまう.
- abc152_d: handstand 2 `c[i][j]` に先頭が i で 末尾が j であるものの個数を O(N)でカウントしておいて,最後に `c[i][j]*c[j][i]`の総和をとる
- abc150_d: semi common multiple.`X= a_i * (p+0.5) = a_i/2 * (2p+1)`と書ける. 2p+1 は奇数なので、このようにかけるためには全ての`a_i`の素因数中の 2 の数が一致していることが必要条件になる.
- abc148_c: lcm = a\*b / gcd(a, b) - abc147_c: 状態は二値の組なので bit 全探索, 状態を決め打ちしたら矛盾の検出は容易\
- abc148_e: 2,4,6..N の積の末尾ゼロの個数は素因数の 10 の個数、つまり素因数中の 2, 5 の数の小さい方. ここで、2,4,...N は明らかに 2 のほうがおおいので 5 の数を数える. 5を因数に複数もつ数を考慮すると、 5 で割り切れる数 + 5x5 で割り切れる数 + 5x5x5 で割り切れる数 の総和がその答えになる. そして末尾が 5 になる数が存在しない性質から、 N/10, N/50, N/250 を見ていけばよい. 
- abc147_d: xor と加算について分配則が成り立ったりはしない. xor は各ビット独立に計算される. - abc145_c:`next_permutation( begin(v), end(v) )`は、辞書順の上でひとつずつ最後まで並び替える
- abc143_c: 二分探索の初期値は両端ともに開区間端にしておくべき - abc141_d: 積で割って小数点切り捨てるのと、ひとつずつ割りながら切り捨てるのは同じ - abc140_e: 区間端のインデックスを集合で管理する. 大きい順に見ていく. 境界条件を楽に管理する.
- abc138_d: C++でも`max(N*Q)=40000000000`(10^10, 百億) 程度の規模ループが走ると 2 秒では終わらない. 木の場合, "あるノードの親" を保持するデータ構造の方が筋が良いことがある
- abc137_c: **ハッシュテーブル**は`O(1)`で任意要素にアクセスできる
- abc137_d: **優先度度付きキュー**は push に`O(logN)`かかるが`O(1)`で最大要素にアクセスできる. 本問のように徐々に広がる範囲の中から最大値を次々求めるときなどに有用
- abc135_c:`10^9`は`int`の外
- abc135_d: 剰余は各桁でバラせば独立なので, 13 x len(S) の dp を用いて, i 桁目までのパターン数から i+1 桁目までのパターン数を計算していける
- abc133_c:`(a*b) % p = ((a % p)*(b % p)) % p`であり, 剰余の世界は p 未満の数しかない\
- abc133_d: WA 漸化式や総和を考えるとアルゴリズミックに解くやり方が見える？`+=`の際には変数の初期化忘れに注意.\
- abc132_d 重複のありえそうなｘ組み合わせは隙間の選び方として考える
- abc131_c:`gcd(a,b) * lcm(a,b) = a*b`境界条件 要注意
- abc129_c: i 番目の状態は有限の事前状態から求まるので dp
- abc128_d: 多次元全探索のループの内側でも変数を書き換える場合コピーする必要がある
- abc125_c: gcd はどの順番で計算してもよい`gcd(X,Y,Z) = gcd(gcd(X,Y),Z) = gcd(X, gcd(Y,Z))` ため、左からの gcd と右からの gcd を計算しておけば、i 番目を除外した gcd は log(min(a,b)) で求まる
- abc124_c: string に添字つけて取り出した文字は char. うっかり char で書かれた数字と int を比較しないように
- abc123_d: A_i + B_j + C_k が上位 K 個に入るためには、A と B だけ見たときに A_i + B_j が上位 K 個に入っていなければならないことを利用して、ソートにかける要素を絞る. また、独自構造体と比較関数による優先度付きキューは `priority_queue<elem, vector<elem>, decltype(comp)> PQ{comp};`
- abc122_c: 1 文字目から i 番目までに出現する"AC"の数で dp をして、区間端で引く
- abc122_d: i-3,i-2,i-1 文字目がなんであったかを保持する二次元 DP. map で持ってもおもしろいかも
- abc121_d: i ビット目が立っているからといって 2^i の倍数ということにはならない. また、 任意の偶数 n について `n ^ (n+1)=1` が成り立つ.
- abc120_d: `10^5` 以下の n でも `n*(n-1)/2` を計算する必要がある場合は要注意. 互いに素な点集合 A と B の元同士のペアの数は `|A|*|B|` で計算できる
- abc118_d: 桁 dp. 桁ごとのコストを配列に入れておくとき, 0 を含まない場合など 0 から順に全部あるわけじゃない場合にずれるので注意（map のほうがいいかも）
- abc117_d: まず xor は桁ごとに独立に考えることができるので, i 桁目ビットを立てた場合と立てなかった場合の増分を桁単位で考えることができる. そこで, K 未満か K 未満未確定かの状態を持つ二進桁 DP で上位ビットから決めていく
- abc116_d: Various Sushi. K 種類とる場合は各種類の最大値をとればよい. K 種類ない場合は番兵を使う. そこから「x 種類以上での最大値」を選んでいくことにすれば、種類数を確実に減らすことにこだわらなくてよくなる.
- abc114_d: 約数の数が 75 である数は、 75 を素因数分解して `3*5*5` としたとき、これらを相異なる素数の指数にしたパターンとして表される （例: `p^2 * q*4 * r^4`, `p^74` など）. そのため、まず N!=1,2,3...N をそれぞれ素因数分解して合算することで全体としての素因数分布を求める.
- abc113_d: Number of Amidakuji. 縦から i 行目までで j 列に到る場合の数で DP をする. dp(0,0)=1 としておいて、ある地点からの遷移を、各行での横線の引き方を bit 全探索して計算する.
- abc111_c: 2 番目に大きい要素まで保持する場合、「max を超える要素を見た場合」だけでなく「max 以下 max_2 以上を見た場合」を忘れずに
- abc110_d: Factorization. 素因数分解の各素数の肩の値をそれぞれ独立に 1~N に割り振る重複組合せ.
- abc108_c: int の自乗や三乗は範囲外になる. キャストするか、はじめから ll にしておく. また, N/(K/p) - N/K で, K で割って p 余る数は出る
- abc108_d: 2 進数表現を考えると当たり前だが、`2^r` までの 2 の冪  のそれぞれに 0 か 1 かをかけて足し合わせると `0` から `2^(r+1)-1` までの整数をそれぞれ一意に表現できる. そこから L になるまで枝を増やす.
- abc107_c: N 本のろうそくのうち、連続する K 本を選ぶ方法は N - K\*\*+ 1\*\* 通り. K 本をひとまとめにした列から一本を選ぶことと等価.
- abc105_c: -2 進数. N を 2 で割れば桁がひとつ落ちて、最下位桁が 2 で割ったあまりに対応する
- abc104_c: 「全部解く/全く解かない」の 2 通りで表せば、各状態に対して「中途半端に解く」問題がひとつ定まることに注目した bit 全探索. データメンバを勝手に書き換えない.\
- abc103_c: 最小公倍数を実際に求めるとオーバーフローしてしまう
- abc102_c: 絶対誤差を最小化するのは中央値. 返すのが argmin か min かはよく確認しておくこと
- abc092_c: 「番号順に訪れる」とある. 問題文はよく読む. 各点間の距離の和から|A\*{i-1} - A\_{i+1}| を足して i の入出を引くほうがはやい\
- abc091_c: x 座標が小さい順に青い点を見ていき, ペア候補点の中で最も y 座標が大きい（貴重でない）点とペアにする. ループの条件の i < N を忘れない
- abc089_c: 生の配列はグローバル変数に置かないと 0 初期化されないことを忘れないように. LL = int\*int とかやっていると, 代入(キャスト)前の演算中にオーバーフローする可能性があるので注意
- abc082_c: 要素カウントなどの際は連想配列 `map<T, T>` を使うとべんり. for (auto paire
  : map) のように取り出せる.
- abc077_c: ソートされた配列に対して `lower_bound(v.begin(), v.end(), val)` で val 以上の最初の要素へのイテレータを二分探索により返す. upper_bound は より大きい.
- abc074_c: 操作の組について全探索する(間に合わない)のではなく、とりうる水量と砂糖量について全探索する.
- abc058_c: 積集合をとるには, `set_intersection(A.begin(), A.end(), B.begin(), B.end, inserter(dst, dst.end()))` が便利.
- abc054_b: 植木算 必要なループが開始しないかもしれない条件に注意
- abc052_c: 素因数の個数 → ある素因数で何回割れるか
- abc050_c: 1e9+7 で割るはずが 1e7 と書いていた. 割る数はよく見よう
- abc048_b: `0` は任意の数で割り切れる
- abc046_c: A,B の比率を x:y とするには`nx >= A and ny >= B` なる最小の自然数 n をかければよく, それは `max(ceil(x/A), ceil(y/B))`
- abc045_c: char で書かれた数字から `0` を引けて int にキャストするとよい. **入力の下限の値にも注意(ループが回らないことなどがある)**
- abc044_c: `dp[j][k][s]` : j までから k 枚選んで合計が s になる選び方の総数. **dp テーブル上でのオーバーフローにも注意**（これで数時間溶かした…）
- abc038_c: `10000 < 10^5`. dp 配列初期化時の桁数はよく確認する. **しゃくとり法**とよぶ
- abc037_c: 植木算に注意.累積和は別の配列に入れておくほうが安全か？
- abc036_c: 座標圧縮は map にキーをいれて value にその順序をインクリメントしながら入れていくと楽. `10^5` 以下程度なら十分高速.
- abc035_c: **いもす法**:区間に対する演算をまとめて計算する. 配列 `a` の 区間 `[l, r]` に `v` を加算する処理について, `a[l] += v; a[r+1] -= v` としておき, `a[i+1] += a[i]` としてゆく. 半開区間であることに注意.
- abc034_c: 剰余の世界での割り算の方法. **フェルマーの小定理** により, p と互いに素な a に対して `a^(p-1)≡1 (mod p)` であることから `a^(p-2)≡a^(-1) (mod p)` となる. つまり mod p の世界では a の乗法逆元は `a^(p-2)` になる. また, `a^b` は, b が偶数なら `d=a^(b/2); return d*d;`とし, 奇数なら`a* a^(b-1)`という再帰関数をかけば log(b) で計算できる.
- abc032_c: **しゃくとり法**. 左端を固定して右端を伸ばせるだけ伸ばし, 伸ばせなくなったら左端をひとつ右に進める. 追い越さないように, 追い付いたら右端も一緒に進める. O(N) で解ける. 半開区間のほうがいい？
- abc031_c: 最大値がマイナスになるかもしれない場合, 最大値をおいておく変数は -INTINF で初期化する必要がある. また、このような場合、内側の最大化が確定してから外側に代入すること
- abc030_c: 配列から条件を満たす最も小さい値を探す → 二分探索などが使える
- abc029_c: p 進数全探索は直接書いてもいいし再帰でかいてもいい.
- abc027_c: ゲーム問では「各プレイヤーにとっての最適戦略」を考えてシミュレーションする.
- abc026_c: いちおう取りうる答えの範囲は見積もっておくべき
- abc025_c: ゲーム木全探索. 得点 a,b について s=a-b を考えると, a の最大化は s の最大化, b の最大化は s の最小化になる. あとルールをよく読む.`同じ文字が書かれていたなら直大くんに、違う文字が書かれていたなら直子さんに点が入る`
- abc023_c: 部屋の中の飴を K 個集める. 起点に飴があった場合に二重カウントを許すとして, 行と列ごとに集計する. またこの場合、各行と列「飴が k 個ある行/列が何個あるか」にしか興味がないので、更にそのように集計する. そこで 飴が i 個ある列数 × K-i 個ある列数を足してゆく. 最後に飴座標を順に見ていくことで、二重カウントによる余分や数え漏らし分を足し引きする.`agg_x[i]` をループするとき, i の範囲は x の数ではなく x の値域になる.
- abc022_c: 最短閉路を求める. 頂点 1 に隣接する点 i を選び, 辺(1,i)を一旦削除して i から 1 への最短経路を求めて(1,i)の長さを足した. ほか、1 からの辺を全部削除したグラフを考えて, 1 に隣接する 2 頂点の最短距離を求めるという手もある. その場合ワーシャルフロイドで全対間経路を求めておくなどするとよい.\*\*頂点数と辺数の変数を混同しないように\*\*
- abc021\*c: そのまま dp を走らせると最短でない経路をカウントしてしまう. そのため,まず最短経路を計算し, 最短経路を達成できる辺(`d[s] + c(s,t) == d[t]`)のみからなる DAG を構成してから dp を計算する. 辺に関する入力ループの最中に最短距離初期化を入れないように.
- abc020_c: 単調増加性を利用した二分探索をかけながら最短経路探索を行う.
- abc018_c: 長方形領域に対して黒マスを避けて塗れるサイズ K の菱形の数. ありうる全マスに対して塗れるかどうか判定すると RxCxK^2 かかって間に合わないので, 「上下方向に白マスがいくつあるか」を RxCxK で記録しておくことで検査を RxCxK で済ませられ、全体として間に合う
- abc017_c: 整数の区間全部を覆わない覆い方の中で最大値を求める. 左/右から i 番目までの最適解をそれぞれ求めた. 一方、区間に対するスコアを足し算だと思っていもす法で求めて、全部訪問したときのスコアから区間の最小値を引くとしてもよい.
- abc016_c: ワーシャルフロイドで一撃だが, 「頂点を 2 つ選んで共通の友達がいるか調べる」でも
- abc015_c: K 進数探索をしたが、たぶん深さ優先探索で再帰をやったほうが楽
- abc014_c: いもす法で累積和を復元しながらその最大値を探すとき、max を入れる変数の初期値を`Array[0]` などにしておかないと, 累積和ループの内側では`Array[0]`をチェックしないことがある
- abc011_c: dp 配列の値が bool の場合、配列の次元を落とすことを考えてみる. `bool dp[N][depth]` は `int dp[N]`を i までにかかる最小手数として、INTINF で初期化して上から更新していくなど.
- abc010_c: 誤差が怖いので T x V にイプシロンを足しておくとよいかも. 2 点からの距離の和が一定の領域は 2 点を焦点とした楕円になる
- abc009_c: 辞書式順序ふたたび. 文字列 S,T の並び替えを許した不一致度は, `sum*{c=a-z} max(0, S に含まれる c の数 - T に含まれる c の数)` とする. 差の絶対値などを取ると余分にカウントしてしまう.
- abc008_c: c と書いてあるコインが表を向いている期待値が求まれば、線型性よりその和が答えになる. その際、c の約数でないコインは無視してよい. どんな約数であるかも考えなくて良い. c の約数の並びだけ考えて、それらの両端含むどこかに c を挿入した際、左側のコインの数が偶数になる確率が求める確率. 約数コインの数が奇数なら 1/2, 偶数なら (S/2 + 1)/(S+1) = (2S + 2)/(2S+2).
- abc007_c: pair で座標管理は first/second を書くのがめんどくさいので構造体を用意したい
