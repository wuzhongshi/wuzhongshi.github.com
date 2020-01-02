-- 创建表
CREATE TABLE news(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT,
    content TEXT,
    created_at TEXT
);

-- 添加信息
INSERT INTO 
news (title, content, created_at) 
VALUES ('hello clang','the first news', '2019-12-30');


INSERT INTO 
news (title, content, created_at) 
VALUES ('新年快乐','新年快乐新年快乐', '2019-12-30');

INSERT INTO 
news (title, content, created_at) 
VALUES ('元旦快乐','元旦快乐元旦快乐', '2020-01-01');