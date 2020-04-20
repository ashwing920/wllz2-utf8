// chinesed.c

#pragma optimize
#pragma save_binary


#include <localtime.h>

#ifndef DATA_DIR
#define DATA_DIR        "/data/"
#endif
#define E2C_DICTIONARY  DATA_DIR + "e2c_dict"

inherit F_SAVE;

// some constatns
static string *c_digit = ({ "零","十","百","千","万","亿","兆" });
static string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
static string *sym_tian = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
static string *sym_di = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });

mapping dict = ([]);

void add_translate(string key, string chn);
void remove_translate(string key);

void create()
{
	seteuid(getuid());
	restore();
}
void remove()
{
	save();
}
string chinese_number(int i)
{
	if (i < 0)
		return "负" + chinese_number(-i);
	if (i < 11)
		return c_num[i];
	if (i < 20)
		return c_digit[1] + c_num[i - 10];
	if (i < 100) {
		if (i % 10)
			return c_num[i / 10] + c_digit[1] + c_num[i % 10];
		else
			return c_num[i / 10] + c_digit[1];
	}
	if (i < 1000) {
		if (i % 100 == 0)
			return c_num[i / 100] + c_digit[2];
		else if (i % 100 < 10)
			return c_num[i / 100] + c_digit[2] +
			c_num[0] + chinese_number(i % 100);
		else if (i % 100 < 10)
			return c_num[i / 100] + c_digit[2] +
			c_num[1] + chinese_number(i % 100);
		else
			return c_num[i / 100] + c_digit[2] +
			chinese_number(i % 100);
	}
	if (i < 10000) {
		if (i % 1000 == 0)
			return c_num[i / 1000] + c_digit[3];
		else if (i % 1000 < 100)
			return c_num[i / 1000] + c_digit[3] +
			c_num[0] + chinese_number(i % 1000);
		else
			return c_num[i / 1000] + c_digit[3] +
			chinese_number(i % 1000);
	}
	if (i < 100000000) {
		if (i % 10000 == 0)
			return chinese_number(i / 10000) + c_digit[4];
		else if (i % 10000 < 1000)
			return chinese_number(i / 10000) + c_digit[4] +
			c_num[0] + chinese_number(i % 10000);
		else
			return chinese_number(i / 10000) + c_digit[4] +
			chinese_number(i % 10000);
	}
	if (i < 1000000000000) {
		if (i % 100000000 == 0)
			return chinese_number(i / 100000000) + c_digit[5];
		else if (i % 100000000 < 1000000)
			return chinese_number(i / 100000000) + c_digit[5] +
			c_num[0] + chinese_number(i % 100000000);
		else
			return chinese_number(i / 100000000) + c_digit[5] +
			chinese_number(i % 100000000);
	}
	if (i % 1000000000000 == 0)
		return chinese_number(i / 1000000000000) + c_digit[6];
	else if (i % 1000000000000 < 100000000)
		return chinese_number(i / 1000000000000) + c_digit[6] +
		c_num[0] + chinese_number(i % 1000000000000);
	else
		return chinese_number(i / 1000000000000) + c_digit[6] +
		chinese_number(i % 1000000000000);
}

string query_save_file()
{
	return E2C_DICTIONARY;
}

string chinese(string str)
{
	if (!undefinedp(dict[str]))
		return dict[str];
	else
		return str;
}

void remove_translate(string key)
{
	map_delete(dict, key);
	save();
}

void add_translate(string key, string chn)
{
	dict[key] = chn;
	save();
}
void dump_translate()
{
	string *k, str;
	int i;

	str = "";
	k = keys(dict);
	for (i = 0; i < sizeof(k); i++)
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	write_file("/CHINESE_DUMP", str);
}
string chinese_time(int time) {
	int t, d, h, m, s;
	string ret;

	t = time;
	s = t % 60;              t /= 60;
	m = t % 60;              t /= 60;
	h = t % 24;              t /= 24;
	d = t;

	if( d ) ret = chinese_number( d ) + "天";
	else ret = "";

	if( h ) ret += chinese_number( h ) + "时";
	if( m ) ret += chinese_number( m ) + "分";
	ret += chinese_number( s ) + "秒";

	return ret;
}
string chinese_month(int date)
{
	mixed *local;
	local = localtime(date);
	return sprintf("%s",chinese_number(local[LT_MON] + 1));
}
string chinese_monthday(int date)
{
	mixed *local;
	local = localtime(date);
	return sprintf("%s月%s日",chinese_number(local[LT_MON] + 1),
		chinese_number(local[LT_MDAY]+1));
}
string chinese_date(int date, int year)
{
	mixed *local;
	write("tset411\n");
	if (date <=0) date=1;
	local = localtime(date);
	local[LT_YEAR] = year;
	return sprintf("%s%s年%s月%s日%s时%s刻",
                sym_tian[local[LT_YEAR] % 10], sym_di[local[LT_YEAR] % 12],
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY] + (local[LT_HOUR] > 23 ? 1 : 0)),
                sym_di[((local[LT_HOUR] + 1) % 24) / 2],
              //chinese_number((local[LT_MIN]+1) % 2 * 2 + local[LT_MIN] / 30 + 1)
                chinese_number(local[LT_MIN] / 15 + 1 + (((local[LT_HOUR] + 1) % 24) % 2) * 4)
				);
}

string chinese_period(int t)
{
	int y, n, d, h, m, s;
	string time;

	s = t % 60;              t /= 60;
	m = t % 60;              t /= 60;
	h = t % 24;              t /= 24;
	d = t % 30;              t /= 30;
	n = t % 12;              t /= 12;
	y = t;

	time = "";

	if(y) time = chinese_number(y) + "年又";
	if(n) time += chinese_number(n) + "个月"        + (strlen(time)?"":"又");
	if(d) time += chinese_number(d) + "天"    + (strlen(time)?"":"又");
	if(h) time += chinese_number(h) + "小时"        + (strlen(time)?"":"又");
	if(m) time += chinese_number(m) + "分"    + (strlen(time)?"":"又");
	time += chinese_number(s) + "秒";

	return time;
}
