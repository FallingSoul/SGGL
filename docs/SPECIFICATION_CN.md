# 规范
## 提交信息规范
### ***格式：<提交类型> [(影响范围)]: <提交描述>***

**PS:<>表示必要，[]表示可选**

e.g.
```
<Fix>(Global): ...
```
+ 提交类型
  1. *Fix*：修正，一般指修正BUG
  2. *Feat*：加入新功能
  3. *Docs*：修改文档
  4. *Style*：规范代码格式
  5. *Refactor*：重构
  6. *Perf*：性能优化
  7. *Test*：提交测试代码
  8. *Chore*：一般其他事务
+ 影响范围
+ 提交描述
  1. *描述主旨*：必选
  2. *详细描述*：可选
  3. *相关问题*：可选
### ***版本回滚***
+ 必须在提交信息前加入"Revert"字样

---

## 命名规范
***所有类型命名开头必须有```sg```字样，宏开头必须是 ```SG_GL``` 或者 ```__SG_GL```***
### 类 & 结构体
+ 采用大驼峰规则，排除开头sg，例如```sgWindowMessage```
### 基础类型
+ 采用全小写
### 变量
+ 采用全小写加下划线，保证可以理解变量作用
+ 私有变量开头必须有```_```（下划线）
  
---

## 结构规范
+ ***除宏以外，所有定义必须在sggl命名空间之内***
+ ***结构层次分明***

---

## 注意事项
+ 不采用```#program once```，而采用宏判断的方式，宏同时也包含了结构信息
e.g.
  ```
  #ifndef __SG_GL_INCLUDE_ONCE__
  #define __SG_GL_INCLUDE_ONCE__
  // TODO
  #endif //!__SG_GL_INCLUDE_ONCE__
  ```
+ 不采用原生类型，如 ```int,short,float``` 等，采用自定义类型
+ 任何sggl源文件必须包含 "family.h"
  
