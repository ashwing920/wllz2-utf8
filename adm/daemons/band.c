// band.c
// 修改：robert 蝴蝶君 Robert_st@sina.com 2000.05.04.

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

#define PASSED_SITES            CONFIG_DIR +"/passed_sites"    // 强行开放站点记录文件
#define BANNED_SITES            CONFIG_DIR +"/banned_sites"    // 强行禁止站点记录文件
#define BANNED_IDS              CONFIG_DIR +"/banned_ids"        // 强行禁止登陆记录文件
#define BANNED_NAMES            CONFIG_DIR +"/banned_name"     // 禁止使用的中文名字。
#define PASSED_PIDS             CONFIG_DIR +"/passed_ids"

string *b_ids;
string *p_sites;
string *b_sites;
string *b_names;
string *b_pids;

void load_sites();
void load_ids();
void load_names();
void load_pids();

void create()
{
        seteuid(getuid());
        load_sites();
        load_ids();
        load_names();
        load_pids();
}

/*－－－－－－－－－－  以下部分为禁止登陆ＩＰ地址的处理部分　－－－－－－－－－－*/

// 读入强行开放及禁止站点的列表
void load_sites()
{
        string *s, file;
        int loop;

        p_sites = ({});
        b_sites = ({});

        file = read_file(PASSED_SITES);
        if (! file) return;
        s = explode(file, "\n");
        for(loop = 0; loop < sizeof(s); loop ++)
                if(s[loop][0] == '#' || s[loop][0] == '\n' || s[loop] == "") continue;
                else p_sites += ({ s[loop] });

        file = read_file(BANNED_SITES);
        if (! file) return;
        s = explode(file, "\n");
        for(loop = 0; loop < sizeof(s); loop ++)
                if(s[loop][0] == '#' || s[loop][0] == '\n' || s[loop] == "") continue;
                else b_sites += ({ s[loop] });
}
// 显示强行禁止站点记录
void print_banned()
{
        for (int i = 0; i < sizeof(b_sites); i++) write(b_sites[i] + "\n");
}

// 判别是否强行禁止的站点
int is_banned(string site)
{
        string *line;

        line = ({});
        line += ({site});

        for (int i = 0; i < sizeof(b_sites); i++)
                if (sizeof(regexp(line, b_sites[i])) == 1) return 1;

        return 0;
}

// 增加强行禁止的站点记录
void add_banned(string site)
{
        b_sites += ({site});
        write_file(BANNED_SITES, b_sites[sizeof(b_sites) - 1] + "\n", 0);
}

// 取消强行禁止的站点记录
void remove_banned(string site)
{
        // write(HIR + MUD_NAME + "对你说：对不起，请您修改 " + BANNED_SITES + " 解禁。\n" NOR);
        rm( BANNED_SITES );
        for (int i = 0; i < sizeof(b_sites); i++)
                if( b_sites[i] != site ) write_file( BANNED_SITES, b_sites[i] + "\n", 0 );
        load_sites();
}
/*－－－－－－－－－－－－－－　结束　－－－－－－－－－－－－－－－－－ */

/*－－－－－－－－－－－－－－　以下部分为强行开放ＩＰ地址的处理　－－－－－－－－－－－－－－－ */

// 判别是否强行开放的站点
int is_pass_id(string site)
{
        string *line;

        line = ({});
        line += ({site});

        for (int i = 0; i < sizeof(p_sites); i++)
                if (sizeof(regexp(line, p_sites[i])) == 1) return 1;

        return 0;
}
// 显示强行开放站点记录
void print_passed()
{
        for (int i = 0; i < sizeof(p_sites); i++) write(p_sites[i] + "\n");
}
// 增加强行开放的站点记录
void add_passed(string site)
{
        p_sites += ({site});
        write_file(PASSED_SITES, p_sites[sizeof(p_sites) - 1] + "\n", 0);
}
// 取消强行开放的站点记录
void remove_passed(string site)
{
        // write(HIR + MUD_NAME + "对你说：对不起，请您修改 " + PASSED_SITES + " 解禁。\n" NOR);
        rm( PASSED_SITES );
        for (int i = 0; i < sizeof(p_sites); i++)
                if( p_sites[i] != site ) write_file( PASSED_SITES, p_sites[i] + "\n", 0 );
        load_sites();
}
/*　－－－－－－－－－－－－－－－　结束　－－－－－－－－－－－－－－－－*/

/*　－－－－－－－－－－－－－－－　以下为禁止登陆ＩＤ的处理部分　－－－－－－－－－－－－*/

void load_ids()
{
        string *s, file;
        int loop;
        b_ids = ({});

        file = read_file(BANNED_IDS);
        if (! file) return;
        s = explode(file, "\n");
        for(loop = 0; loop < sizeof(s); loop ++)
                if(s[loop][0] == '#' || s[loop][0] == '\n' || s[loop] == "") continue;
                else b_ids += ({ s[loop] });
}
// 判别是否禁止登陆的玩家
int is_ban_id(string id)
{
        string *line;

        line = ({});
        line += ({id});

        for (int i = 0; i < sizeof(b_ids); i++)
                if (sizeof(regexp(line, b_ids[i])) == 1) return 1;

        return 0;
}

// 显示禁止登陆的玩家记录
void print_ban_id()
{
        for (int i = 0; i < sizeof(b_ids); i++) write(b_ids[i] + "\n");
}

// 增加禁止登陆的玩家记录
void add_ban_id(string id)
{
        b_ids += ({id});
        write_file(BANNED_IDS, b_ids[sizeof(b_ids) - 1] + "\n", 0);
        load_ids();
}
// 取消禁止登陆的玩家记录
void remove_ban_id(string id)
{
        rm( BANNED_IDS );
        for (int i = 0; i < sizeof(b_ids); i++)
                if( b_ids[i] != id ) write_file( BANNED_IDS, b_ids[i] + "\n", 0 );
        load_ids();
}
/* －－－－－－－－－－－－－－－　结束　－－－－－－－－－－－－－－－－　*/

/* －－－－－－－－－－－－－－－　以下为禁止使用的中文名称处理　－－－－－－－－－－－－－－－　*/

//读入禁止使用的中文名称记录
void load_names()
{
        string *s, file;
        int loop;
        b_names = ({});

        file = read_file(BANNED_NAMES);
        if (! file) return;
        s = explode(file, "\n");
        for(loop = 0; loop < sizeof(s); loop ++)
                if(s[loop][0] == '#' || s[loop][0] == '\n' || s[loop] == "") continue;
                else b_names += ({ s[loop] });
}
// 判别是否禁止使用的中文名称
int is_ban_name(string name)
{
        string *line;

        line = ({});
        line += ({name});

        for (int i = 0; i < sizeof(b_names); i++)
                if (sizeof(regexp(line,b_names[i])) == 1) return 1;

        return 0;
}

// 显示禁止使用的中文名称
void print_ban_name()
{
        for (int i = 0; i < sizeof(b_names); i++) write(b_names[i] + "\n");
}

// 增加禁止使用的中文名称
void add_ban_name(string name)
{
        b_names += ({name});
        write_file(BANNED_NAMES, b_names[sizeof(b_names) - 1] + "\n", 0);
        load_names();
}
// 取消禁止使用的中文名称
void remove_ban_name(string name)
{
        rm( BANNED_NAMES );
        for (int i = 0; i < sizeof(b_names); i++)
                if( b_names[i] != name ) write_file( BANNED_NAMES,b_names[i] + "\n", 0 );
        load_names();
}
/*　－－－－－－－－－－－－－－－　结束　－－－－－－－－－－－－－－－　*/

/*　－－－－－－－－－－－－－－－　以下为强行开放ＩＰ地址的ＩＤ的处理　－－－－－－－－－－－ */

void load_pids()
{
        string *s, file;
        int loop;
        b_pids = ({});

        file = read_file(PASSED_PIDS);
        if (! file) return;
        s = explode(file, "\n");
        for(loop = 0; loop < sizeof(s); loop ++)
                if(s[loop][0] == '#' || s[loop][0] == '\n' || s[loop] == "") continue;
                else b_pids += ({ s[loop] });
}
// 判断是否为开放特殊登陆的玩家记录

int is_passed_id(string id)
{
        string *line;

        line = ({});
        line += ({id});

        for (int i = 0; i < sizeof(b_pids); i++)
                if (sizeof(regexp(line, b_pids[i])) == 1) return 1;

        return 0;
}
// 显示开放特殊登陆的玩家记录
void print_pass_id()
{
        for (int i = 0; i < sizeof(b_pids); i++) write(b_pids[i] + "\n");
}

// 增加禁止登陆的玩家记录
void add_pass_id(string id)
{
        b_pids += ({id});
        write_file(PASSED_PIDS, b_pids[sizeof(b_pids) - 1] + "\n", 0);
        load_pids();
}
// 取消禁止登陆的玩家记录
void remove_pass_id(string id)
{
        rm( PASSED_PIDS );
        for (int i = 0; i < sizeof(b_pids); i++)
                if( b_pids[i] != id ) write_file( PASSED_PIDS, b_pids[i] + "\n", 0 );
        load_pids();
}
