@echo off

rem 入力・出力ディレクトリパスを受取ったら
rem そこのファイルを全て検索し、
rem 1つずつファイルパスと出力ディレクトリパスをmainプログラムへ渡す

rem 引数1 入力ディレクトリパス
rem 引数2 出力ディレクトリパス



set IN_FILE_PATH=%1
set OUT_PATH=grouping_photos_out/%2

echo %IN_FILE_PATH%
echo %OUT_PATH%