= 執筆環境

DTPと呼ばれるものが一般化した現代、ひとまず執筆環境としてはコンピュータを使ったものを前提としてこの章では色々紹介してみます。

== DTPツールを使う

あまり技術同人誌では出番が無いかも知れませんが、Adobe InDesign を使えば凝った本を作成できるでしょう。また、Microsoft Word なんかもお手軽に同人誌を書けます。効率的に書くならフォーマットをうまくいじるといいです。

DTPツールを使う場合、いきなりそのソフトで書き始めるより、テキストエディタで本文を書いてから、そのソフトに流し込み、図を貼り付けたり、参照関係調整をするほうが楽に書ける気がします。細かい使い勝手に左右されるのではなく、文章、構成を作り込む方に集中すると良いと思います。ざっくり5割から8割くらいの分量を書くまではテキストエディタで十分だと思います。

#@# FIXME: 加筆もとむ

== テキストファイルをコンパイルする系

なんらかのテキストエディタを使って、ソースコードをコンパイルするというのはソフトウェア技術者にとってはなじみ深いと思います。技術書典で出されている本の多くはそういった手法が使われています。

  * Re:VIEW
  * Markdown
  * HTML+CSS
  * Sphinx

だいたいここらへんが人気あるところでしょうか。

=== Re:VIEW

Re:VIEW@<fn>{Re:VIEW}は現時点ではkmuto@<fn>{kmuto}さん他40人以上の開発者が参加するオープンソースな組み版ソフトです。実際にいくつもの出版社が採用しているプロユースのソフトですが、技術系同人誌でもよく使われるなど、プロもアマチュアも使うとても便利なソフトです。
//footnote[Re:VIEW][@<href>{http://reviewml.org/}]
//footnote[kmuto][@<href>{https://github.com/kmuto}]

技術系同人誌でよく使われるのは、技術同人誌の大家であるTechBoosterさんがちょうどそのまんま、ノウハウを惜しみなく詰め込んだリポジトリを公開しているため、環境さえ構築できれば、そのまま書き始められるという利点があるためです。

  * @<href>{https://github.com/TechBooster/ReVIEW-Template}
  * @<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2}

後者は実際にコミケC89で販売されていた「技術書をかこう！　はじめてのRe:VIEW　改訂版」という本のソースコードに該当します。

本書は、ReVIEW-Templateをベースに書かれています。

  * @<href>{https://github.com/onestop-techbook/c93-onestop-techbook}

#@# 詳しくは@<chap>{01-writing.re}に書いています。

Re:VIEWでは、ASCIIで使われていた画期的な電子出版（Editor's Work Bench）の書式をベースにしつつ簡易化した記述方法で本を書きます。Markdownや他のWikiとは違う少し癖があるように感じられる記法ですが、組み版に特化していて必要十分な機能を持っています。

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

@<list>{list-test}は実際のRe:VIEWのソースコードです。なんなら @<href>{https://github.com/onestop-techbook/c93-onestop-techbook} を開いてみてください。本書の原稿はRe:VIEWで書かれていて Github で公開されています。

@<code>{=} で始まる行は見出しです。特に@<code>{=}のようなイコール記号が1つのものは章です。

  * @<code>{=} 章
  * @<code>{==} 節
  * @<code>{===} 項
  * @<code>{====} 段
  * @<code>{=====} 小段

@<code>{//} で始まる行はブロック命令です。

@<code>{@}<code>{fuga}のような命令はインライン命令です。

詳しくは公式Wiki@<fn>{format-ja}をご覧ください。
//footnote[format-ja][@<href>{https://github.com/kmuto/review/blob/master/doc/format.ja.md}]

=== Markdown

Markdownは技術者向けの簡易言語です。お手軽かつ、統一フォーマットとしての側面があり、Githubで使えるGFM（Github Fravored Markdown@<fn>{GFM}）が事実上の標準となっています。
//footnote[GFM][@<href>{https://github.github.com/gfm/}]

ブログやドキュメントをMarkdownで書いたり、プレゼンのスライドをMarkdownで作成するなどがよくある使われ方ですが、Markdownでも技術書を執筆できます。

md2review@<fn>{md2review}を使えば、Markdownで書いた本をRe:VIEWを経由して高品質なPDFなどを作成できます。
//footnote[md2review][@<href>{https://github.com/takahashim/md2review}]

Gitbook@<fn>{gitbook}という、Markdownで執筆できるツールもあります。Re:VIEWほどの高品質ではありませんが、これでも十分同人誌を作成できる品質かつ、Re:VIEWよりは遙かに楽です。
//footnote[gitbook][@<href>{https://github.com/GitbookIO/gitbook}]

=== HTML+CSS

電子書籍のフォーマットとして標準となっているEPub形式ですが、実質HTML+CSSです。頑張ってCSSでうまく装飾すれば、印刷して同人誌にすることもできます。

#@# FIXME: 加筆もとむ

=== reST（Sphinx）

MarkdownよりはマイナーですがreSTという記述形式があり、Sphinxというツールを使うという手もあります。Sphinx@<fn>{sphinx}はPythonの公式ドキュメントを作るために生まれたものですが、これで同人誌を作成もできます。reST形式についてはreStructuredText入門@<fn>{reST}を読むといいでしょう。
//footnote[sphinx][@<href>{http://docs.sphinx-users.jp/}]
//footnote[reST][@<href>{http://docs.sphinx-users.jp/rest.html}]

#@# FIXME: 加筆もとむ

====[column] テキストエディタ：@erukiti

テキストエディタ、何を使っていますか？Windowsのメモ帳で頑張ってる強者なひともいらっしゃるかもしれませんが、エンジニアに人気のテキストエディタというと、Vim や Emacs という昔ながらのエディタもありますが、最近はよりモダンな Atom や Visual Studio Code があります。

Visual Studio Code（VSCode） は名前の通り Visual Studio なのでテキストエディタというよりは IDE なのですがとても軽量でテキストエディタとしてもとても良いので最近シェアを急激に伸ばしているようです。実際、本書や別の本も、Re:VIEW プラグインをインストールした VSCode で書いています。筆者が試した限りだと Atom より動作が軽量かつ、JavaScript/TypeScript での IDE としての機能が筆者にとっての必要十分なので、愛用しているエディタです。

Markdown で執筆する場合は、Markdown 専門のツールを使うという手もあります。Windows でも Mac でも最近はいろいろな Markdown 執筆ツールがあるので、それらを利用してみるという手もあります。最近はウェブサービスで Markdown 形式をサポートしているケースも多く、ブログを書いたりするのにも便利です。

====[/column]