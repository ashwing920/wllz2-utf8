// natured.c

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <localtime.h>
#define GAME_TIME(t)            (t - 971000000)
#define TIME_TICK (time()*60)
static int current_day_phase;
mapping *day_phase;

private mapping *read_table(string file);
private void auto_save();
void select_day_phase();
static int night;
int is_night() { return night; }
private void create()
{
	seteuid(getuid());
	day_phase = read_table("/adm/etc/nature/day_phase");
	select_day_phase();
}
mixed *query_localtime(int t)
{
        mixed *lt;

        t = GAME_TIME(t);
        lt = localtime((t % 86400) * 365);
        lt[LT_MON]++;
        lt[LT_YEAR] = t / 86400;
        return lt;
}
int query_hour()        { return query_localtime(time())[LT_HOUR]; }
int query_day()         { return query_localtime(time())[LT_MDAY]; }
int query_month()       { return query_localtime(time())[LT_MON]; }
int query_year()        { return query_localtime(time())[LT_YEAR]; }
void update_day_phase()
{
        string msg;

        msg = color_filter(day_phase[current_day_phase]["outcolor"] +
                           day_phase[current_day_phase]["time_msg"] + "\n" NOR);
        message("outdoor:vision", msg, all_interactive());
        if (! undefinedp(day_phase[current_day_phase]["event_fun"]))
                call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
}

void select_day_phase()
{
        mixed *lt;
        int i, t, n;
        remove_call_out("select_day_phase");

        // Get minutes of today.
        lt = query_localtime(time());
        t = lt[LT_HOUR];
        // Find the day phase for now.
        for (i = 0; i < sizeof(day_phase) - 1; i++)
                if (t < day_phase[i + 1]["hour"]) break;

        if (i >= sizeof(day_phase) - 1)
        {
                // the last hour
                n = 24 - t;
                i = 0;
        } else
                n = day_phase[i + 1]["hour"] - t;

        // calculate the call out time
        n = n * 60 - lt[LT_MIN];
        n = n * 60 / 365 + 1;
        if (n < 1) n = 1;
        call_out("select_day_phase", n);
        if (i != current_day_phase)
        {
                current_day_phase = i;
                update_day_phase();
        }
}
private void event_dawn()
{
	night = 0;
}

private void event_sunrise()
{
	night = 0;
}

private void event_morning()
{
	night = 0;
}

private void event_night()
{
	auto_save();
	night = 1;
}
void event_midnight()
{
        string msg;
        int m, d;

        m = query_month();
        d = query_day();

        msg = 0;
        switch (m * 100 + d)
        {
        case  321:
                msg = HIG "春天终于到了，经过了漫长的冬季，万物开始复苏。\n" NOR;
                break;
        case  622:
                msg = HIR "夏天来临了，天气越来越热，所有的生物都异常活跃。\n" NOR;
                break;
        case  923:
                msg = HIY "已然是秋天了，大地一片金黄，正是收获的时期。\n" NOR;
                break;
        case 1222:
                msg = HIW "来自北方的寒流扫过大地，万物又开始了寂静的休眠。\n" NOR;
                break;
        }

        if (msg)
                message("vision", HIC "【季节天时】" + msg,
		        msg, all_interactive());

        switch(m)
        {
        //spring weather
        case 3: case 4: case 5:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/spring_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/spring_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/spring_wind");
                        break;
                }
                break;
        //summer weather
        case 6: case 7: case 8:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/summer_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/summer_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/summer_wind");
                        break;
             }
             break;
        //autumn weather
        case 9: case 10: case 11:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/autumn_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/autumn_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/autumn_wind");
                        break;
                }
                break;
        //winter weather
        case 12: case 1: case 2:
                switch(random(3))
                {
                case 0:
                        day_phase = read_table("/adm/etc/nature/winter_rain");
                        break;
                case 1:
                        day_phase = read_table("/adm/etc/nature/winter_sun");
                        break;
                case 2:
                        day_phase = read_table("/adm/etc/nature/winter_wind");
                        break;
                }
                break;
        default:
                day_phase = read_table("/adm/etc/nature/day_phase");
        }
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
        object *ob;
        object env;
        int    ic;
        int    con;
        int    month;
        string ill, msg;
        int    i;

        if (random(4)) return;
        switch(month = query_month())
        {
        case 3: case 4: case 5:
                ill = "ill_kesou";
                msg = HIG + "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" + NOR;
                ic  = 5;
                break;
        case 6: case 7: case 8:
                ill = "ill_zhongshu";
                msg = HIG+"突然你胸臆之间一阵翻腾，你中暑了。\n" + NOR;
                ic  = 5;
                break;
        case 9: case 10: case 11:
                ill = "ill_shanghan";
                msg = HIG+"陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n"+NOR;
                ic  = 5;
                break;
        case 12: case 1: case 2:
                ill = "ill_dongshang";
                msg = HIG+"你肢体末端一阵僵直，看来你被冻伤了。\n"+NOR;
                ic  = 0;
                break;
        }

        if (random(4) == 0)
        {
                ill = "ill_fashao";
                msg = HIG+"你偶感风寒，竟而发起烧来。\n"+NOR;
        }

        ob = users();
        for (i = 0; i < sizeof(ob); i++)
        {
                if (! objectp(env = environment(ob[i]))) continue;
                if (! env->query("outdoors")) continue;
                if (! living(ob[i])) continue;
                con = ob[i]->query_con();
                con = con / 2 + random(con);
                switch (ill)
                {
                case "ill_shanghan":
                case "ill_dongshang":
                        con += ob[i]->query_temp("apply/warm") +
                               env->query_temp("warm");
                        break;

                case "ill_zhongshu":
                        con -= ob[i]->query_temp("apply/warm") +
                               env->query_temp("warm");
                        break;
                }

                if (con + ic < 25 )
                {
                        ob[i]->apply_condition(ill, 30 - con);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
	return convert_color(day_phase[current_day_phase]["outcolor"]) +
	day_phase[current_day_phase]["desc_msg"] + NOR;
}
string game_time()
{
        mixed *lt;
        string *ms = ({ "冬", "春", "夏", "秋", });

        lt = query_localtime(time());
		
        return sprintf("%s年%s%s月%s日%s时",
                       chinese_number(lt[LT_YEAR]),
                       ms[((lt[LT_MON]) % 12) / 3],
                       chinese_number(lt[LT_MON]),
                       chinese_number(lt[LT_MDAY]),
                       chinese_number(lt[LT_HOUR]), );
}
string ture_time(int time)
{
	mixed *t;
	t = localtime(time);

	return sprintf("%d-%d-%d %d:%d:%d", t[LT_YEAR] ,t[LT_MON] + 1, t[LT_MDAY],t[LT_HOUR], t[LT_MIN], t[LT_SEC]);
}
private mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}
mapping *query_day_phase() { return day_phase; }

private void auto_save()
{
	object *ob,link_ob;
	int i;

	ob = filter_array(children(USER_OB),(: userp :));

	for(i=0;i<sizeof(ob);i++){
		if(!environment(ob[i]) || !ob[i]->query_temp("link_ob")) continue;
		link_ob = ob[i]->query_temp("link_ob");
		if(ob[i]->save() && link_ob->save())
			message("system", HIC"【武林史记】你的资料已经被载入史册。\n"NOR,ob[i]);
		else
			message("system", HIC"【武林史记】官府遭人洗劫了，资料无法载入。\n"NOR,ob[i]);
	}
	CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("共有 %d 位使用者资料被保存！",sizeof(ob)));
	return;
}
