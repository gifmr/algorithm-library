# おまけ

## これは何？

外出先でPC忘れてWindows環境しかなくても、すぐ競プロできるようにするため自分用に作った

## 環境構築

### WSL導入

[参考] https://qiita.com/AokabiC/items/e9312856f588dd9303ed

PowerShell 上で以下を実行

```PowerShell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

Microsoft Store から **Ubuntu LTS** をインストール

Ubuntuを起動し、WSL上で以下を実行

```bash
sudo apt install build-essential
sudo apt install gdb
```

あとはこのリポジトリを clone し、VSCode で開けば `.vscode` 配下の設定ファイルを読み込んで WSL がターミナルとして使われるようになる

#### 最低限入れておくべき拡張機能

- C/C++
- Better C++ Syntax
- WSL workspaceFolder
- Remote - WSL

## 実行手順

プロジェクト配下に適当に `cpp` ファイルを作ればよい

- ビルド: `ctrl` + `shift` + `B`
- デバッグ: 直下に `problem.in` ファイルを作成、入力値を設定して `F5`