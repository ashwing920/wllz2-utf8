// database.h

// 是否采用永久连接
#define STATIC_LINK
// 是否调试状态
// #define DEBUG
// 是否允许分站新玩家注册
// #define REFUSE_NEW_PLAYER

#ifndef DATABASE
nosave string DATABASE               = "/data/mud.db3";
#endif
#ifndef DB_USER
nosave string DB_USER                = "avhot";
nosave string DB_HOST				 = "localhost";
#endif
nosave string USER_TABLE             = "users";
nosave string DB_CRYPT               = "PASSWORD";
