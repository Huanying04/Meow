# Meow
喵喵語。一種圖靈完備的語言。是Brainfuck和Ook!的變種。

# 編寫
簡單的Hello World!程式。
```meow
meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow? meow? meow! meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow? meow. meow? meow. meow? meow. meow? meow. meow? meow! meow! meow? meow! meow. meow! meow! meow! meow! meow. meow! meow! meow. meow! meow! meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow. meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow. meow! meow! meow! meow! meow. meow! meow? meow. meow? meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow. meow. meow! meow! meow! meow! meow! meow! meow! meow. meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow. meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow. meow! meow! meow. meow! meow! meow. meow! meow! meow. meow. meow!
```
喵喵語的用法與Brainfuck相同，每個字元狀態間需要用一個空格間隔。
| 喵喵語    | brainfuck | 用途 |
|-----------|-----------|------|
| meow! meow. | > | 指標加一 |
| meow? meow. | < | 指標減一 |
| meow! meow! | + | 指標指向的位元組的值加一 |
| meow? meow! | - | 指標指向的位元組的值減一 |
| meow. meow! | . | 輸出指標指向的單元內容（ASCII碼） |
| meow. meow? | , | 輸入內容到指標指向的單元（ASCII碼） |
| meow? meow? | [ | 如果指標指向的單元值為零，向後跳轉到對應的`]`指令的次一指令處 |
| meow! meow? | ] | 如果指標指向的單元值不為零，向前跳轉到對應的`[`指令的次一指令處 |

詳細編寫方法請參閱Brainfuck: https://zh.wikipedia.org/wiki/Brainfuck

## 使用方法
### meow -text
```
meow -text meowLang
```
直接執行meowLang。

示例：
* 輸入：
```
 meow -text "meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow? meow? meow! meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow? meow. meow? meow. meow? meow. meow? meow. meow? meow! meow! meow? meow! meow. meow! meow! meow! meow! meow. meow! meow! meow. meow! meow! meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow. meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow. meow! meow! meow! meow! meow. meow! meow? meow. meow? meow. meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow! meow. meow! meow! meow. meow. meow! meow! meow! meow! meow! meow! meow! meow. meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow. meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow? meow! meow. meow! meow! meow. meow! meow! meow. meow! meow! meow. meow. meow!"
 ```
* 結果：
```
Hello World!
```

### meow -meow
```
meow -meow filename
```
執行檔案filename。
