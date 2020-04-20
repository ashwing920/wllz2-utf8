// roomd.c
// Written by Doing Lu 1998/11/14

// 接受来自SECURITD的查询，返回一个object存盘的文档名，SECURITYD比较这个
// 文档名和来自object的请求写入的文档名，如果一致，方可写入。

//#pragma optimize
//#pragma save_binary

void create()
{
	seteuid(getuid());
}

string get_file_name(object ob)
{
	string file;
	if (objectp(ob))
	{		
		file = base_name(ob) + ".sav"; 
		// 如果这是一个普通的可纪录的房屋，存盘文件要存放在/data/room中
		// 如果不是纪录的房屋，又不是私有房屋，不能纪录。
		if (ob->query("recordable_room")) file = "/data/room" + file; else
		if (! ob->query("private_room")) file = "";
	} else
		file = "";

	return file;
}
