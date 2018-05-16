# QSqlQueryModel
别人的代码，仅做学习记录用。运行环境windows下QT5.7+MySQL5.7。Qt数据库QSqlQueryModel的使用方法。
QSqlQueryModel是一个只读的数据库模型，该代码通过重载虚函数flags(),setData(），更改data()，refresh（），setName（），创建继承自QSqlQueryModel
的自己的类，自己的模型。使之可以更改表格的内容，更改数据的显示。
运行结果
点击按钮“query”,就会出现要显示的表格。点击第二列就可对第二列的表格进行修改。但是按钮“query”与显示函数是信号与槽的模式，所以修改完数据后，要重新点击按钮
“query”,才能将更新的内容显示出来。这是个BUG.
本来想在refresh()更新函数中，通过定时器信号与槽连接到显示函数，但是好像由于QSqlQueryModel不是继承自QObject的，所以信号与槽机制不能用，
暂时没有想到更好的解决方法，就这样吧。
