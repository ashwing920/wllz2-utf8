// BackUpD.c 

#include <ansi.h>
#include <localtime.h>

inherit F_DBASE;

#define BACKUP_DATE     7               // the oldest's backup (days)

static int state;

#define SLEEPING        0
#define GET_READY       1
#define GET_READY_2     2
#define BACKUPING       3

#define ADM_CMD_RM      "/cmds/adm/zrm"
#define ADM_CMD_CP      "/cmds/adm/zcp"

static int *tlist = ({ 0,550,559,600});
static int *hlist = ({ 45, 1, 1, 1 });

// 通知一次准备的时间：凌晨4:50分
// 通知再次准备的时间：凌晨4:59分
// 开始进行备份的时间：凌晨5:00分
// 凌晨五点以后到第二天凌晨4:50分之前属于休眠状态

void backup_data();
private void change_state(int new_state);
private void sys_info(string msg);
private int assure_not_exist(string bkdir);
private int is_recent_time(int y, int m, int d, int cy, int cm, int cd);

// return the time of prompt
int is_backuping()              { return state != SLEEPING; }

// return the time of backup
int query_backup_time()         { return tlist[BACKUPING]; }

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "备份精灵");
	sys_info("备份系统已经启动。");
	state = SLEEPING;
	set_heart_beat(hlist[state]);
}

int clean_up()
{
	return 1;
}

void heart_beat()
{
	mixed lt;
	int ti;

	seteuid(ROOT_UID);
	lt = localtime(time());
	ti = lt[LT_HOUR] * 100 + lt[LT_MIN];

	switch(state)
	{
	case SLEEPING:
		if (ti < tlist[GET_READY] || ti > tlist[GET_READY_2])
			// not change state
			break;
		// chanage state to "GET_READY";
		change_state(GET_READY);
		break;

	case GET_READY:
		if (ti < tlist[GET_READY_2])
			break;

		// change state to "GET_READY_2";
		change_state(GET_READY_2);
		break;

	case GET_READY_2:
		if (ti < tlist[BACKUPING])
			break;

		// change state to "GET_READY_2";
		change_state(BACKUPING);

		// the last function will change to "SLEEPING" state
		// after backing
		break;

	default:
		change_state(SLEEPING);
		break;
	}

	// reset heart beat
	set_heart_beat(hlist[state]);
}

private void change_state(int new_state)
{
	mixed lt;

	lt = localtime(time());
	switch (new_state)
	{
	case GET_READY:
	case GET_READY_2:
		if (lt[LT_HOUR] * 100 + lt[LT_MIN] != tlist[BACKUPING])
		{
			message_system(sprintf("现在是 %d 点 %d 分，系统将在 %d 点 %d 分自动备份所有玩家的数据，期间游戏会有停滞。",
				       lt[LT_HOUR], lt[LT_MIN],
				       (tlist[BACKUPING] / 100) % 100,
				       tlist[BACKUPING] % 100));
			break;
		} else
			new_state = BACKUPING;

	case BACKUPING:
		state = new_state;
		message_system(sprintf(HIY "现在是 %d 点 %d 分，系统开始自动备份所有玩家数据，请稍候..." NOR,lt[LT_HOUR], lt[LT_MIN]));
		LOGIN_D->set_lock(1);
		backup_data();
		message_system(sprintf(HIW"系统已经处理完备份工作，祝您玩得愉快。" NOR,lt[LT_HOUR], lt[LT_MIN]));
		LOGIN_D->set_lock(0);
		// after backup, change state to SLEEPING
		new_state = SLEEPING;
		break;
	case SLEEPING:
		break;
	}

	// change to new state
	state = new_state;
	return;
}

// backup
// copy current /DATA to /BACKUP_DIR/yyyy.mm.dd, if the directory
// has been existed, then remove the directory first.
// after that, I will check wether the other directory in backup
// directiry was the backup of recently(BACKUP_DATE days), if not,
// I will remove it.
void backup_data()
{
	string bkdir;
	mixed lt;
	mixed *file;
	int count;
	int i;

	if (! is_root(previous_object()))
	{
		write(HIR "YOU HAVE NO ACCESS TO BACKUP\n" NOR);
		return;
	}

	seteuid(getuid());

	sys_info(sprintf("备份工作开始。", bkdir));
	lt = localtime(time());

	// because LT_MON is from 0..11, so I must add 1
	lt[LT_MON]++;
	bkdir = sprintf("%s%d-%d-%d", BACKUP_DIR,
			lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]);
	if (! assure_not_exist(bkdir))
	{
		sys_info(sprintf("备份失败：无法删除(%s)。", bkdir));
		return;
	}

	// backup data
	sys_info("复制"+DATA_DIR+"到"+bkdir);
	count = ADM_CMD_CP->copy_dir(DATA_DIR, bkdir);
	//count = ADM_CMD_CP->main(this_object(),DATA_DIR, bkdir);
	if (count)
		sys_info(sprintf("总共有%d个文件被保存到(%s)中。", count, bkdir));

	// clear the older backup data
	file = get_dir(BACKUP_DIR, -1);
	for (i = 0; i < sizeof(file); i++)
	{
		int y, m, d;

		reset_eval_cost();
		if (file[i][1] != -2)
			// not directory
			continue;

		if (sscanf(file[i][0], "%d-%d-%d", y, m, d) != 3)
			// not backup directory
			continue;

		if (is_recent_time(y, m, d, lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]))
			// is the receant backup, won't delete
			continue;

	       ADM_CMD_RM->rm_dir(BACKUP_DIR + file[i][0]);
		 //ADM_CMD_RM->main(this_object(),BACKUP_DIR + file[i][0]);
		sys_info(sprintf("备份(%s)已经被自动删除。", file[i][0]));
	}

	sys_info(sprintf("备份工作完毕。", bkdir));
}

// check that y/m/d wether or not close cy/cm/cd(current time)
private int is_recent_time(int y, int m, int d, int cy, int cm, int cd)
{
	if (y > cy) return 1;   // future backup? laugh
	if (y == cy)
	{
		// the same year
		if (m > cm) return 1;   // maybe future backup
		if (m == cm)
		{
			// the same month
			if (d <= cd - BACKUP_DATE) return 0;
			return 1;
		}
		if (m != cm - 1) return 0;
		switch (m)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			cd += 31;
			break;
		case 2:
			cd += 28;
			if ((y % 4) == 0 && (y % 100) != 0) cd++;
			break;
		default:
			cd += 30;
			break;
		}
		if (d <= cd - BACKUP_DATE) return 0;
		return 1;
	}
	if (y != cy - 1) return 0;
	if (m != 12 || cm != 1) return 0;
	cd += 31;
	if (d <= cd - BACKUP_DATE) return 0;
	return 1;
}

private int assure_not_exist(string bkdir)
{
	switch(file_size(bkdir))
	{
	case -1:
		return 1;

	case -2:
		ADM_CMD_RM->rm_dir(bkdir);
		//ADM_CMD_RM->main(this_object(),bkdir);
		return (file_size(bkdir) == -1);

	default:
		return rm(bkdir);
	}
}

private void sys_info(string msg)
{
	CHANNEL_D->do_channel(this_object(), "sys", msg);
	log_file("backup", ctime(time()) + ": " + msg + "\n");
}
