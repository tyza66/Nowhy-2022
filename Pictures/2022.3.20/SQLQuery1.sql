USE 实验1;
/*Student（学号Sno，姓名Sname，性别Ssex，年龄Sage，所在院系Sdept）*/
CREATE TABLE Student(Sno CHAR(9) PRIMARY KEY,Sname CHAR(10) UNIQUE,Ssex CHAR(2),Sage INT,Sdept CHAR(30));/*Course（课程号Cno，课程名Cname，先修课程号 Cpno ，学分Ccredit）*/CREATE TABLE Course(Cno CHAR(2) PRIMARY KEY,Cname CHAR(30) UNIQUE,Cpon CHAR(2),Ccredit INT);/*SC（学号Sno，课程号Cno，成绩Grade）*/CREATE TABLE SC(Sno CHAR(9) PRIMARY KEY,Cno CHAR(8) ,Grade INT);/*向Student表添加记录*/INSERT INTO Student VALUES('200212128','张丹','女',18,'计算机科学与技术');INSERT INTO Student VALUES('200215122','李海霞','女',20,'数学');INSERT INTO Student VALUES('200212129','赵扩','女',19,'计算机科学与技术');
INSERT INTO Student VALUES('200212130','李想','男',18,'通信工程');
INSERT INTO Student VALUES('200212131','徐闻','男',21,'通信工程');
INSERT INTO Student VALUES('200215123','林红','女',21,'软件工程');
INSERT INTO Student VALUES('200215126','张海洋','男',19,'软件工程');
INSERT INTO Student VALUES('200215127','杨洋','女',22,'软件工程');
INSERT INTO Student VALUES('200212132','李广','男',21,'数学');
/*向Course表添加记录*/
INSERT INTO Course VALUES('1','计算机基础',null,3);
INSERT INTO Course VALUES('2','C语言程序设计','1',4);
INSERT INTO Course VALUES('3','数学',null,2);
INSERT INTO Course VALUES('4','信息系统',null,4);
INSERT INTO Course VALUES('5','数据库','2',4);
INSERT INTO Course VALUES('6',' 操作系统','1',3);
INSERT INTO Course VALUES('7','数据结构','2',4);
/*向SC表添加记录*/
INSERT INTO SC VALUES('200212131','1',70);
INSERT INTO SC VALUES('200215123','1',84);
INSERT INTO SC VALUES('200215127','4',95);
INSERT INTO SC VALUES('200215128','1',40);
INSERT INTO SC VALUES('200212129','1',59);
INSERT INTO SC VALUES('200212130','1',60);
INSERT INTO SC VALUES('200212168','2',94);
INSERT INTO SC VALUES('200215121','2',92);    
INSERT INTO SC VALUES('200215122','2',85);