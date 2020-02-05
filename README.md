# Programming Contest Practice

problems: https://kenkoooo.com/atcoder/#/user/optie
graph:   http://atcoder-scores.herokuapp.com/graph?user=optie


## ABC memo
abc153_e: ナップザックDP \
abc153_f: 貪欲でも良いがそのままでは間に合わない. 爆風の影響にある敵の体力をひとつずつ引いていく(N**2になりうる)のではなく Queue で区間を記憶しておく. vector(N) で初期化するときは容量ジャストにする. ソートするときに 0初期化された領域まで含んでしまう.
abc148_c: lcm = a*b / gcd(a, b) \
abc147_c: 状態は二値の組なので bit 全探索, 状態を決め打ちしたら矛盾の検出は容易\
abc145_c: `next_permutation( begin(v), end(v) )` は、辞書順の上でひとつずつ最後まで並び替える \
abc141_d: 積で割って小数点切り捨てるのと、ひとつずつ割りながら切り捨てるのは同じ \
abc140_e: 区間端のインデックスを集合で管理する. 大きい順に見ていく. 境界条件を楽に管理する. \
abc138_d: C++でも `max(N*Q)=40000000000`(10^10, 百億) 程度の規模ループが走ると 2 秒では終わらない. 木の場合, "あるノードの親" を保持するデータ構造の方が筋が良いことがある \
abc137_c: **ハッシュテーブル**は`O(1)`で任意要素にアクセスできる \
abc137_d: **優先度度付きキュー**は push に`O(logN)`かかるが`O(1)`で最大要素にアクセスできる. 本問のように徐々に広がる範囲の中から最大値を次々求めるときなどに有用 \
abc135_c: `10^9`は`int`の外 \
abc135_d: 剰余は各桁でバラせば独立なので, 13 x len(S) のdpを用いて, i桁目までのパターン数からi+1桁目までのパターン数を計算していける \
abc133_c:`(a*b) % p = ((a % p)*(b % p)) % p`であり, 剰余の世界は p 未満の数しかない\ 
abc133_d: WA 漸化式や総和を考えるとアルゴリズミックに解くやり方が見える？`+=`の際には変数の初期化忘れに注意. 
\ abc131_c:`gcd(a,b) * lcm(a,b) = a*b`境界条件 要注意 \ abc129_c: i番目の状態は有限の事前状態から求まるのでdp \ 
abc125_c: gcd はどの順番で計算してもよい`gcd(X,Y,Z) = gcd(gcd(X,Y),Z) = gcd(X, gcd(Y,Z))` ため、左からの gcd と右からの gcd を計算しておけば、i 番目を除外した gcd は log(min(a,b)) で求まる \
abc124_c: string に添字つけて取り出した文字は char. うっかり char で書かれた数字と int を比較しないように \
abc122_c: 1 文字目から i 番目までに出現する"AC"の数で dp をして、区間端で引く \
abc111_c: 2 番目に大きい要素まで保持する場合、「max を超える要素を見た場合」だけでなく「max 以下 max_2 以上を見た場合」を忘れずに \
abc108_c: int の自乗や三乗は範囲外になる. キャストするか、はじめから ll にしておく. また, N/(K/p) - N/K で, K で割って p 余る数は出る \
abc107: N 本のろうそくのうち、連続する K 本を選ぶ方法は N - K **+ 1** 通り. K 本をひとまとめにした列から一本を選ぶことと等価.
abc105_c: -2進数. Nを2で割れば桁がひとつ落ちて、最下位桁が2で割ったあまりに対応する \
abc104_c: 「全部解く/全く解かない」の2通りで表せば、各状態に対して「中途半端に解く」問題がひとつ定まることに注目したbit全探索. データメンバを勝手に書き換えない.\
abc103_c: 最小公倍数を実際に求めるとオーバーフローしてしまう \
abc102_c: 絶対誤差を最小化するのは中央値. 返すのが argmin か min かはよく確認しておくこと \
abc092_c: 「番号順に訪れる」とある. 問題文はよく読む. 各点間の距離の和から|A_{i-1} - A_{i+1}| を足して i の入出を引くほうがはやい\
abc091_c: x座標が小さい順に青い点を見ていき, ペア候補点の中で最もy座標が大きい（貴重でない）点とペアにする. ループの条件の i < N を忘れない \
abc089_c: 生の配列はグローバル変数に置かないと0初期化されないことを忘れないように. LL = int*int とかやっていると, 代入(キャスト)前の演算中にオーバーフローする可能性があるので注意 \
abc082_c: 要素カウントなどの際は連想配列 `map<T, T>` を使うとべんり. for (auto pair : map) のように取り出せる. \
abc077_c: ソートされた配列に対して `lower_bound(v.begin(), v.end(), val)` で val 以上の最初の要素へのイテレータを二分探索により返す. upper_bound は より大きい. \
abc074_c: 操作の組について全探索する(間に合わない)のではなく、とりうる水量と砂糖量について全探索する. \
abc058_c: 積集合をとるには, `set_intersection(A.begin(), A.end(), B.begin(), B.end, inserter(dst, dst.end()))` が便利. \
abc054_b: 植木算 必要なループが開始しないかもしれない条件に注意 \
abc052_c: 素因数の個数→ある素因数で何回割れるか \
abc050_c: 1e9+7 で割るはずが 1e7 と書いていた. 割る数はよく見よう \
abc048_b:  `0` は任意の数で割り切れる \
abc046_c: A,Bの比率を x:y とするには`nx >= A and ny >= B` なる最小の自然数 n をかければよく, それは `max(ceil(x/A), ceil(y/B))` \
abc045_c: char で書かれた数字から `0` を引けてintにキャストするとよい. **入力の下限の値にも注意(ループが回らないことなどがある)** \
abc044_c: `dp[j][k][s]` : j までから k 枚選んで合計が s になる選び方の総数. **dpテーブル上でのオーバーフローにも注意**（これで数時間溶かした…） \
abc038_c: `10000 < 10^5`. dp配列初期化時の桁数はよく確認する.  **しゃくとり法**とよぶ \
abc037_c: 植木算に注意.累積和は別の配列に入れておくほうが安全か？ \
abc036_c: 座標圧縮はmapにキーをいれてvalueをインクリメントしていくと楽. `10^5` 以下程度なら十分高速. \
abc035_c: **いもす法**:区間に対する演算をまとめて計算する. 配列 `a` の 区間 `[l, r]` に `v` を加算する処理について, `a[l] += v; a[r+1] -= v` としておき, `a[i+1] += a[i]` としてゆく