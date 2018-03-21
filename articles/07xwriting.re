= 執筆環境

DTP（Desk Top Publishing）と呼ばれるものが一般化した現代、執筆環境としてはコンピュータを使ったものを前提として、この章ではその環境、ツールを色々紹介します。（Text：erukiti／佐々木俊介） 

== DTPツールを使う

ソフト上で文字やイラストを並べて作業をすすめるソフトを、広い意味でDTPソフトと呼称することができます。プロも使っているDTPソフトといえば、Adobe InDesingが業界標準です。あまり技術同人誌では出番が無いかも知れませんが、Adobe InDesign を使えば凝った本を作成できるでしょう。

また、技術書を書く場合、ワープロソフトがそのままDTPソフトになります。したがって、Microsoft Wordを使うとお手軽に同人誌を書けます。Wordは、たいていのPCにインストールされているし、日常的に使うこともあるでしょうから、とりあえず使い方に困ることは少ないかと思います。そういう意味で、初めて技術書を書く場合の執筆ツールとしてはBestな選択です。ツールの選択や使い方で迷う前に本文を書き上げてしまいましょう。なお、効率的に書くならスタイル機能を使いこなすことをお薦めします。付録には技術書を書く場合のWordの使い方エッセンスを収録していますし、専門書@<fn>{techbookword}も「技術書典シリーズ」で刊行されています。あわせて参照することをおすすめします。

//footnote[techbookword][『エンジニア・研究者のためのWordチュートリアルガイド』@<href>{https://nextpublishing.jp/book/9363.html}]

また、ワープロソフトとして有名な一太郎も、ここ数年は同人誌執筆層を取り込みにかかっています。最新の一太郎では、主要な印刷所のフォーマットに合わせたpdfを直接出力できる機能が追加されたようです。

さて、ワープロやDTPツールを使う場合、いきなりそのソフトで書き始めるより、テキストエディタで本文を書いてから、そのソフトに流し込み、図を貼り付けたり、参照関係調整をするほうが楽に書けるのではないかと筆者は感じています。まずは細かい使い勝手に左右されるのではなく、文章の内容や構成を作り込む方に集中すると良いと思います。ざっくり5割から8割くらいの分量を書くまではテキストエディタで十分でしょう。

== テキストファイルをコンパイルする系の版組ツールを使う

なんらかのテキストエディタを使って、ソースコードをコンパイルするというのはソフトウェア技術者にとってはなじみ深いと思います。技術書典で頒布されている本の多くはそういった手法が使われています。

　　・Re:VIEW

　　・Markdown

　　・TeX/LaTeX

だいたいここらへんが人気あるところでしょうか。いずれも、本文を書いて、体裁に関する命令を間にはさみ、コンパイルするとpdfなどの入稿可能なファイルが出力されます。

=== Re:VIEW

Re:VIEW@<fn>{Re:VIEW}は現時点ではkmuto@<fn>{kmuto}さんを中心に40人以上の開発者が参加するオープンソースな組版ソフトです。実際にいくつもの出版社が採用しているプロユースのソフトですが、技術系同人誌でもよく使われるなど、プロもアマチュアも使うとても便利なソフトです。
//footnote[Re:VIEW][@<href>{http://reviewml.org/}]
//footnote[kmuto][@<href>{https://github.com/kmuto}]

技術系同人誌でよく使われるのは、技術同人誌の大手であるTechBoosterがそのノウハウを惜しみなく詰め込んだリポジトリを公開しているため、環境さえ構築できれば、そのまま書き始められるという利点があるためです。


　　・@<href>{https://github.com/TechBooster/ReVIEW-Template}

　　・@<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2}

後者は実際にコミケC89で販売されていた「技術書をかこう！　はじめてのRe:VIEW　改訂版」という本のソースコードに該当します。

じつは本書の同人誌バージョンもGithubで全て公開されています。@<href>{https://github.com/onestop-techbook/c93-onestop-techbook}というリポジトリが、本書のソースコードなのです。環境を整えれば、本書のPDFやepubを生成できます。本書は、@<tt>{ReVIEW-Template}をベースに書かれています。

Re:VIEWでは、アスキー（当時）で使われていた画期的な電子出版システム「EWB（Editor's Work Bench）」の書式をベースにしつつ簡易化した記述方法で本を書きます。Markdownや他のWikiとは違う少し癖があるように感じられる記法ですが、組み版に特化していて必要十分な機能を持っています。

おおまかに分けて、行単位の命令と文章の中に入れるインライン命令で構成されています。

//listnum[list-test][リストのテスト]{
#@mapfile(sample/01-writing/hoge.re)
= Re:View はこんな感じでかきますよー の章

== ほげー

ふがー@<code>{@}<fn>{fuga}
//footnote[fuga][ふがー]

ぴよー

@<code>{#@#} コメント
#@end
//}

#@# リストの中でもRe:Viewのインライン命令を解釈してしまうので要注意
#@# #@ で始まる行に関しても、プリプロセッサの都合があるので、こんな感じに

たとえば@<list>{list-test}は実際のRe:VIEWのソースコードです。

@<code>{=} で始まる行は見出しです。特に@<code>{=}のようなイコール記号が1つのものは章です。


　　・@<code>{=} 章

　　・@<code>{==} 節

　　・@<code>{===} 項

　　・@<code>{====} 段

5段階以上の項目を作ることも可能ですが、読みやすさを考えるとここまでで抑えたほうが無難でしょう。

@<code>{//} で始まる行はブロック命令です。

@<code>{@}<code>{fuga}のような命令はインライン命令です。

詳しくは公式Wiki@<fn>{format-ja}を読むのが一番なのですが、意外に不親切なところのあるドキュメントなことと、たびたびこのページのお世話になるので、ここではよく使う記法について簡単に解説します。
//footnote[format-ja][@<href>{https://github.com/kmuto/review/blob/master/doc/format.ja.md}]

//table[review-basic][Re:VIEWの基本構文]{
名称	ルール	概要・備考
段落	1行以上の空行をはさむと別の段落になる	HTMLでいうP
見出し	=ではじまる行	=の個数で、章・節・項・段という感じで増えます。HTMLで言うH1, H2, H3, H4, H5
コラム	====[column]から====[/column]まで	=の個数はあまり気にせず4決め打ちとかでもOK
箇条書き	空白と*で始まる行	先頭に空白を忘れないことと、ネストは、** のように重ねること
コメント	#@# ではじまる行	コメント
プリプロセッサ命令	#@mapfile(ファイル名)から#@end	外部ファイルを取り込む。サンプルソースなどに大活躍
//}

プロプロセッサ命令は、@<code>{review-preproc}というコマンドを叩くことで処理できます。

//listnum[review-sample-basic][基本構文のサンプル]{
段落1

段落2

段落3

@<code>{=} 章見出し(H1)

@<code>{==} 説見出し(H2)

見出しの前後は空行にしておいた方が無難です。

 * 箇条書き
 * かじょうがき

@<code>{#@#} コメント
@<code>{#@#} FIXME: これからすごい大作を執筆する

@<code>{//}listnum[source-code][ソースコード]{
@<code>{#@}mapfile(sample/chap-sugoi/friends.js
@<code>{#@}end
@<code>{//}}

@<code>{====[column]} エモくコラムを語る

コラム本文

@<code>{====[/column]}

大体これも命令行の前後は開けておく方が無難。Re:VIEW様の機嫌を損ねてはいけない。
//}

//table[review-block][Re:VIEWブロック命令]{
命令	引数	概要・備考
//listnum	[ID][キャプション][言語(省略可能)]	プログラミング関連なら一番よく使うリスト表記
//list	[ID][キャプション][言語(省略可能)]	行番号なしリスト
//emlist	[キャプション(省略可能)][言語(省略可能)]	リスト番号が付かない (キャプションの省略も可能) リストで、行番号なし
//emlistnum	[キャプション(省略可能)][言語(省略可能)]	リスト番号が付かない (キャプションの省略も可能) リストで、行番号あり
//cmd	なし	コマンドライン操作専用のリスト。listnumでも問題なし。ちょっとわかりやすいくらい
//image	[ID][キャプション][オプション(省略可能)]	オプションでよく使うのはscale=0.5など(横幅に対するスケーリング比率)
//table	[ID][キャプション]	表のセル区切りはハードタブ、空白のセルは.で表現
//quote	なし	引用
//footnote	[ID][中身]	脚注
//bibpaper	[ID][キャプション]	参考文献
//lead	なし	リード文
//}

//listnum[sample-block][ブロック構文のサンプル]{
@<code>{//}listnum[sample][サンプル][js]{
const hoge = 'ほげ'

// javascript でっせー

console.log(hoge)
@<code>{//}}

というようなサンプルソース@<code><@><list>{sample}を書いてみました。

@<code>{//}cmd{
$ sudo rm -rf /
@<code>{//}}

@<code>{//}image[sugoi][すごい画像]

@<code>{//}table[camp][キャンプ]{
名称  説明
----------------------------
志摩りん  ソロキャンパー。でも最近なでしこに浸食されてみんなでキャンプを楽しむのも悪くないと思ってる
各務原なでしこ  美味しそうにメシを食う。ひたすら食う。とにかく食う。やたら元気
斉藤恵那  熊とトラとチワワ100匹を放ってりんちゃんを殺そうとした女。でも空腹で返り討ちに合う
大垣千明  男前めがね
犬山あおい  関西弁(の影響の強い岐阜県民らしい)
@<code>{//}}

※ハードタブ区切りであることに注意。

@<code>{//}quote{
なんか名言っぽいヤツとか
@<code>{//}}

@<code>{//}footnote[fuga][ふがー]

@<code>{//}bibpaper[bible][ばいーぼ]

@<code>{//}lead{
文章の冒頭にあるテキスト。その章のまとめなどを記述するとわかりやすい。
@<code>{//}}
//}

//table[review-inline][Re:VIEWインライン命令]{

命令	概要・備考

@<code>{@}<tt>{...}	等幅
@<code>{@}<code>{...}	ソースコードを本文に貼り付ける時に使用。等幅。
@<code>{@}<list>{ID}	リストを参照する (対応: list, listnum, emlist, emlistnumなど)
@<code>{@}<img>{ID}	図を参照する (対応: image, indepimageなど)
@<code>{@}<table>{ID}	表を参照する
@<code>{@}<fn>{ID}	脚注を参照する
@<code>{@}<bib>{ID}	参考文献を参照する
@<code>{@}<chap>{章ID}	chap, title, chapref など、章番号・タイトル・その組み合わせに変換される
@<code>{@}<column>{コラムID}	コラムを参照する
@<code>{@}<href>{URL}	ハイパーリンクを貼る (PDFやepubで有効)
//}


@<code>{@}<tt>{...}と@<code>{@}<code>{...}の使い分けは、変数名など名前空間のあるものや識別子、演算子などにソースコードを表現する時@<code>{@}<code>{...}を使います。ただLaTeXを初めとしてPDFのコンパイル結果の大半はttとcodeで同じ。HTMLの時だけスタイルシートで変更可能。通常はどちらかで統一しましょう。

//listnum[sample-inline][インライン命令のサンプル]{
@<code>{@}<tt>{JavaScript}には@<code>{@}<code>{await}という命令があります。これは@<code>{@}<code>{async}関数の中で使える命令で、非同期処理の完了を待ってくれるというものです。
//}

====[column]明示的に空行を入れる方法：親方

Re:viewでは、2行以上の空行は無視されます。改行はbrで入れられるのですが、あとがき部分で著者ごとのコメントを明示的に区切りたい場合に困りました。
暗黙の型宣言さんから、「改行　全角スペース　改行」とすると任意の改行ができる、というノウハウの提供をいただきました。


全角スペースのみの段落ができますので、実質的に空行が入ります。なるほどなるほど。

====[/column]

=== Markdown

Markdownは技術者向けの簡易言語です。お手軽かつ、統一フォーマットとしての側面があり、Githubで使えるGFM（Github Fravored Markdown@<fn>{GFM}）が事実上の標準となっています。
//footnote[GFM][@<href>{https://github.github.com/gfm/}]

ブログやドキュメントをMarkdownで書いたり、プレゼンのスライドをMarkdownで作成するなどがよくある使われ方ですが、Markdownでも技術書を執筆できます。

md2review@<fn>{md2review}を使えば、Markdownで書いた本をRe:VIEWを経由して高品質なPDFなどを作成できます。
//footnote[md2review][@<href>{https://github.com/takahashim/md2review}]

また、md2inao@<fn>{md2inao}を使えば、Markdownで書いた文章をInDesignに取り込めるように変換できます。
//footnote[md2inao][@<href>{https://github.com/naoya/md2inao}]

Gitbook@<fn>{gitbook}という、Markdownで執筆できるツールもあります。Re:VIEWほどの高品質ではありませんが、これでも十分同人誌を作成できる品質かつ、Re:VIEWよりは遙かに楽です。
//footnote[gitbook][@<href>{https://github.com/GitbookIO/gitbook}]

#@# FIXME: 加筆もとむ

=== TeX/LaTex

おっと、TeXも忘れちゃいけません。Re:VIEWはTeXのフロントエンドでありPDF生成など裏側ではTeXが走っていますが、一方で本家TeXの作法はだいぶ複雑です。情報系、数学系、工学系の人は一度は触ったことがあるかと思いますが……使い慣れないと難しいようです。自由度も高く、数式は確かにきれいに書けますが、これを期にTeXを始めようというのはあまりおすすめできません。

なお、数式を多用する場合、しかも微分積分、あるいは累乗や添字が飛び交うような文章、その他の数学記号が攻めてくるような文章を書く場合は選択肢に入るでしょう。

なお、フロントエンドとして、LyX@<fn>{LyX}を使うというのは良い選択です。TeXのおまじないがかなり軽減されていて、ワープロソフト／DTPソフトとしてかなり使い勝手が良くなります。
//footnote[LyX][@<href>{https://www.lyx.org/WebJa.Home}]

== テキストベースの執筆環境でつかうもの

さて、ワープロやDTPソフトウェアを使わない場合、どうやってテキストを執筆するべきでしょうか。この本ではGithubとRe:Viewを主軸として執筆しています。エンジニアに馴染みやすく多人数での執筆に向いています@<fn>{solo}。技術書典で出展されている同人誌ではよく見られる構成です。まずは執筆環境の概要を説明します。
//footnote[solo][もちろん個人の執筆にも向いています。]

=== バージョン管理システム

一人で書く場合ならともかく、本書のように合同誌の場合はどうするべきでしょうか？Google Documentのように、リアルタイムに共同編集ができるサービスを使うのも手ですが、git及びgithubを使うととても楽になります。

gitはエンジニアがもっともよく使っているバージョン管理ツールです。Linuxの作者Linus氏が、Linuxの開発に耐える大規模バージョン管理ツールが無いことにブチ切れて開発したものです。gitより以前は Subversionというソフトがよく使われていましたが、圧倒的にgitの方が使い勝手がよく、あっという間に普及しました。

gitのことがさっぱりわからないという人には、『わかばちゃんと学ぶ Git使い方入門@<fn>{wakaba}』をおすすめします。
//footnote[wakaba][@<href>{http://www.c-r.com/book/detail/1108}]

バージョン管理ツールというのは、おおざっぱにいうとソースコードをタイムマシン的にバックアップして管理するものです。これを履歴といいますが、gitでは履歴の差分を省スペースで保持する仕組みなので、容量を気にせずソースコードの履歴を残せます。

====[column] ファイル管理をシステム化する利点

Windowsを使っていて、@<tt>{スケジュール.backup.バージョン1.最新版.old(3).txt}のようなファイルを見かけたことはありませんか？ファイルをコピーしてファイル名で履歴管理しようとする陥る罠です。どれが最新なのかわからないという問題があります。では解決方法として@<tt>{スケジュール.2017-11-11.txt}という命名ルールで縛ろうとしてみます。この場合更新頻度が一日一回におさまればいいですが、同じ日に更新しようとした場合さらにルールが必要になります。たとえば@<tt>{スケジュール.2017-11-11.01.txt}でしょう。ですが、同時に別々の人が更新しようとした場合にはどうなるでしょうか？それに、いちいち人間が手で日付いじるの面倒ですよね？

そこでバージョン管理ツールです。たとえばgitならば、gitに@<tt>{スケジュール.txt}を登録するだけです。コミットという作業をするだけで勝手にソースコード貯蔵庫（リポジトリ）に保管されます。いつの時点の@<tt>{スケジュール.txt}も探し出せます。ログ参照・グラフ参照・検索などさまざまな方法で楽かつ高速で探し出せます。

ファイル名で管理するという原始的なことをする時代ではなくなったのです。

====[/column]

そして GitHub@<fn>{github} はgitを活用した世界最大のソースコードSNSで、エンジニアにとっては名刺代わりといってもいいものです。エンジニアにとっての文化的標準でもあります。たとえば、Markdownと呼ばれる文章の簡易記法は、GitHubのMarkdown（Github Fravored Markdown）が事実上の標準となっていますし、gitがエンジニアの標準になったのも、GitHubの存在がとても大きいのです。
//footnote[github][@<href>{https://github.com/}]

GitHubは多人数でソースコードを同時開発するのにとても向いている便利なサービスです。別にソースコードといってもプログラミングに限定する必要はありません。本の原稿もソースコードです。そのソースコードをGitHubに預けるのです。自分のPCが吹っ飛んでもGitHubにソースコードを置いてる限り悲嘆する必要はありません@<fn>{local-commit}。
//footnote[local-commit][ローカルでの変更点をGitHubに送ってないときは、もちろん悲しいことになります]

====[column] SNS としての Github

SNS といえば Twitter や Facebook が有名ですが、GitHubもコミュニケーション機能が豊富です。

issue（イシュー）はそのプロジェクトにおける問題を話合う掲示板のようなものです。issueはよほどのことが無い限り誰でも書けます。ソフトウェアに対するバグ報告・質問が寄せられたり、チーム内での設計議論なんかも行われています。

Pull-Request（PR / プルリク）はGitHubの一番の特徴ともいえるものです。ある有名な OSS@<fn>{OSS} のプロジェクトがあったとして、あなたがバグを見つけたとします。このときissueで報告するのも手ですが、あなた自身がバグを直してそれが反映されれば手っ取り早くありませんか？それをするのがプルリクです。いきなりプルリク単体を投げると困惑されるかもしれないので、issueで問題提起しつつ、「ハハハ、こんなバグがあったから直したぜ」と言って一緒にプルリクも投げれば、きっとあなたはヒーローになれるでしょう。
//footnote[OSS][オープンソースソフトウェアの略で、誰でも自由にソースコードを読んだり改変できるソフトウェアです。OSSの登場によって、ソフトウェア開発の世界は一気に書き換わりました。]

他にもプロジェクト用の Wiki や進捗管理ツールなども内包していて、エンジニアにとってGitHubは手放せないのです。

====[/column]

=== Docker

Dockerは、ミニマムなLinux実行環境をコンテナという独立した空間に閉じ込めて実行するものです。Dockerについて詳しく語り出すとインフラの本一冊書けるので詳しくは説明しませんが、Dockerfileというファイルさえ用意しておけば、WindowsでもMacでもLinuxでも、同じLinuxコンテナが動きます。そして幸いなことに Re:VIEW関連全てがインストールされたDockerfileが公開されている@<fn>{review-docker}ので、それを使うだけRe:VIEW環境を構築できます。
//footnote[review-docker][@<href>{https://github.com/vvakame/docker-review}]

DockerはWindows環境だとまだ色々問題がありますが、MacやLinux環境なら動かしやすいでしょう。そして、Dockerの利点は、クラウドのサービスで動かしやすいというのもあります。次に説明するWercker CIはまさにその性質を活用しています。

=== Wercker CI

Re:VIEWで書かれた原稿はPDFやepubなどの形式として出力（コンパイル）しないと本にはなりません。インストールさえちゃんとしていればRe:VIEWのコンパイルは簡単ですが、チームで執筆する場合、それぞれの人の環境に左右されずにコンパイルできる方が楽です。とくにそれは自動化しておきたいものです。GitHubに登録された原稿が自動でコンパイルされてPDFなどに変換されていれば最高ですよね。しかもデータの出力だけじゃありません。自動で校正するツールもあります。そういったツールで「この原稿ちょっとマズいんでは？」という指摘を全自動で出すことも簡単です。

自動でコンパイルをするという願いを叶えてくれるものをCI（Continuous Integration@<fn>{CI}）といい、GitHubと連動してくれるCIのサービスが何種類かあります。自前でサーバーを立てる必要はありません。ユーザー登録して、簡単な設定をするだけです。最近はリポジトリに設定ファイルを1つ追加して、GitHub連動の設定をするだけというお手軽なCIサービスが主流です。

さて、今回説明するのはWercker@<fn>{wercker}というサービスです。このサービス元々スタートアップとしてはじまったもので、後にOracle@<fn>{Oracle}社に買収されました。経営している会社はともかくとして、Werckerは使いやすさ、設定の簡単さが売りです。他のCIサービスではオレオレルールを理解しないと使えないものもありますが、WerckerではDockerさえ理解していればほとんどオレオレルールを意識する必要はありません。
//footnote[CI][日本語では継続的インテグレーションといい、自動でコンパイルやユニットテストを走らせるもので、エンジニアの生産性を支えるものです。このジャンルではJenkinsが有名ですがGUIで設定しなければいけないJenkinsは最近では敬遠される傾向があります。]
//footnote[wercker][@<href>{http://www.wercker.com/}]
//footnote[Oracle][オラクルと聞くとついつい身構える人もいるかもしれませんが、werckerはとてもよいサービスです。]

他にもCircleCIなど有名なCIサービスは幾つもありますが、Docker対応しているサービスが一番望ましいです。さきほども軽く説明したとおりRe:VIEWの環境整備はDockerがあれば簡単なためです。

@<href>{https://app.wercker.com/onestop-techbook/c93-onestop-techbook/runs}は実際に筆者がセットアップしたwerckerの結果表示ページです。

=== テキストエディタ

テキストエディタ、何を使っていますか？Windowsのメモ帳で頑張ってる強者なひともいらっしゃるかもしれませんが、エンジニアに人気のテキストエディタというと、VimやEmacsという昔ながらのエディタもありますが、最近はよりモダンなAtom@<fn>{atom}やVisual Studio Code@<fn>{vscode}があります。

中でもVisual Studio Code（VSCode）は名前の通りVisual StudioなのでテキストエディタというよりはIDEなのですが、とても軽量でテキストエディタとしてもとても使い勝手がよく、最近シェアを急激に伸ばしているようです。実際、筆者は本書や別の本も、Re:VIEWプラグインをインストールしたVSCodeで書いています。筆者が試した限りだとAtomより動作が軽量かつ、JavaScript/TypeScriptでのIDEとしての機能が筆者にとっての必要十分なので、愛用しているエディタです。

Markdownで執筆する場合は、Markdown専門のツールを使うという手もあります。WindowsでもMacでも最近はいろいろなMarkdown執筆ツールがあるので、それらを利用してみてもいいでしょう。最近はウェブサービスでMarkdown形式をサポートしているケースも多く、ブログを書いたりするのにも便利です。

//footnote[vscode][@<href>{https://code.visualstudio.com/}]
//footnote[atom][@<href>{https://atom.io/}]

== 環境整備

Re:VIEWを手元で動かすには最低限Rubyが必要になります。そしてPDFを出力する場合はLaTeXも必要になります。MacやLinuxだとそれなりにノウハウも提供されており、設定も楽ですが、Windowsで環境を整える場合はかなり面倒です。Windows10のWindows Subsystem for Linuxを使えると大分楽かもしれません。ただ、どの環境にせよ、LaTeXはとにかく色々と面倒です。Dockerを使わずに自前で環境構築をするなら、かなりの調査と研究が必要になるでしょう。主に必要なのは以下の2点です。

　　・Rubyをインストールする（Re:VIEWがRubyで作られているため）

　　・PDF変換をするために LaTeX をインストールする

=== Dockerをインストールする

Docker for Windows@<fn>{docker-for-windows} や Docker for Mac@<fn>{docker-for-mac}を使うのが手っ取り早いでしょう。
//footnote[docker-for-windows][@<href>{https://www.docker.com/docker-windows}]
//footnote[docker-for-mac][@<href>{https://www.docker.com/docker-mac}]

=== Dockerで動かす

//cmd{
$ docker run --rm -v `pwd`:/work vvakame/review /bin/sh -c "cd /work/articles ; review-pdfmaker config.yml"
//}

@<tt>{/work/articles} という指定はこの本でのディレクトリ構成です。

たったこれだけです。なんと簡単なことでしょうか。

=== Macで環境を構築する

基本的にはHomebrew@<fn>{Homebrew}とbrewcaskを活用するといいでしょう。
//footnote[Homebrew][@<href>{https://brew.sh/index_ja.html}]
//footnote[brewcask][@<href>{https://caskroom.github.io/}]

//cmd{
$ brew cask install mactex
//}

あとはRubyは好きな方法でインストールしておくといいでしょう。システムにすでに入っているものを使う、Homebrewでインストールする、rbenvを使う、anyenv+rbenvを使うなどの手段があります。
//footnote[rbenv][@<href>{https://github.com/rbenv/rbenv}]
//footnote[anyenv+rbenv][@<href>{https://github.com/riywo/anyenv}]

=== Windows で環境を構築する

TeXのインストールには、TeXLive@<fn>{TeXLive}を使うのが最近の鉄板のようです。
//footnote[TeXLive][@<href>{https://user.ecc.u-tokyo.ac.jp/users/user-15826/wiki/?TeX/Install}]

Rubyのインストールには、RubyInstaller@<fn>{ruby-installer2}を使うといいようです。
//footnote[ruby-installer2][@<href>{https://github.com/oneclick/rubyinstaller2/releases}]

TeX（W32TeX）とRubyを使って「Windows 7上に」Re:VIEW環境を構築する方法は付録に掲載しています。

====[column] 技術書はWordでも書ける

本書はRe:VIEW＋GitHubで並行執筆という環境を構築しており、環境構築手順から記事になっているため、それがベストな解とおすすめしていると思われるかもしれません。確かに、差分管理や原稿出力などにおいて素晴らしい面も多々あり、是非オススメしたい環境ではあるのですが、一方で一から環境設定をすることにハードルを感じることがあるかもしれません。

結論から言ってしまえば、Wordでも普通に本は書けるので、環境構築で挫折しそうになるくらいなら、さくっとWordで書いてしまいましょう。Wordも若干の癖があるソフトですが、業務用PC、あるいは家庭用PCにもほぼ標準的にインストールされていることもあり、一度も使ったことがないという人はかなり少ないでしょう。ということは、とっかかりの操作方法に悩む必要がないソフトだといえます。また、比較的編集中の見た目と印刷結果が近いので、直感的な執筆には向きます。TeXやInDesignとかは作法がかなり厳しかったり、操作を覚えてまともに書けるようになるまでがかなりたいへんです。

書き始めるためのハードルはできるだけ下げて、とにかく最初の本を書き上げることを優先すべきです。その上でWordがクソだ！とおもったら、他の環境を試せばよいのです。いきなり使ったことないツールを使い始めて、そのツールの使い方習得に忙殺され、本が完成しないというのは本末転倒です。執筆ツールはあくまで執筆ツールです。（Text：親方）

====[/column]