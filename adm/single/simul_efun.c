/// simul_efun.c

//#pragma optimize
//#pragma save_binary

#include "/adm/simul_efun/info.c"
#include "/adm/simul_efun/ansi.c"
#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/color.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
#include "/adm/simul_efun/user.c"
#include "/adm/simul_efun/ntefun.c"
#include "/adm/simul_efun/util.c"
// This must be after gender.c
#include "/adm/simul_efun/message.c"


void create()
{
	seteuid(getuid());
	write("simul_efun 成功加载！\n");
}
