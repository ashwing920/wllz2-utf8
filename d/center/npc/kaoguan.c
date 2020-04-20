// kaoguan.c - 考官
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;
int in_ask, can_answer, answer;
void create()
{
        set_name("考官", ({ "kao guan", "guan" }) );
        set("long", @LONG
他是一名考官，一脸严肃，脸上没有多少的笑容。
LONG
);

        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 42);
        set("per", 23);
        set("combat_exp",50000+random(10000));
        set("env/wimpy", 40);
        set("get_potential" , 100);
        setup();

        carry_object("/clone/cloth/magenta-pao")->wear(); 
        add_money("silver",10);
}

void init()
{
        add_action("do_quest", "quest");
        add_action("do_answer", "huida");
        add_action("do_answer", "=");
}

int do_quest()
{
        object *list;
        string oper, temp1, temp2;
        int a, b, c, i;
        
        if( in_ask ) return 1;

        a = random(100) + 1;
        b = random(100) + 1;
        switch( random( 8 ) ) {
                case 0: 
                        answer = a + b;
                        oper = chinese_number(a) + "加上" + chinese_number(b) 
                                + (random(2) ? "是" : "等于") + "多少？";
                        break;
                case 1: 
                        answer = a - b;
                        oper = chinese_number(a) + "减去" + chinese_number(b)
                                + (random(2) ? "是" : "等于") + "多少？";
                        break;
                case 2: 
                        if( a * b < 200 ) {
                                answer = a * b;
                                oper = chinese_number(a) + "乘上" + chinese_number(b)
                                        + (random(2) ? "是" : "等于") + "多少？";
                        } else {
                                answer = ( a * b ) % 10;
                                oper = chinese_number(a) + "乘上" + chinese_number(b) 
                                        + (random(2) ? "之" : "的") + "个位数"
                                        + (random(2) ? "是" : "等于") + "多少？";
                        }
                        break;
                case 3: 
                        answer = a % b;
                        oper = chinese_number(a) + "除以" + chinese_number(b)
                                + (random(2) ? "之" : "的") + "余数"
                                + (random(2) ? "是" : "等于") + "多少？";
                        break;
                case 4:
                        oper = chinese_number(a) + "和" + chinese_number(b) 
                                + (random(2) ? "之" : "的") + "最大公因数" 
                                + (random(2) ? "是" : "等于")  + "多少？";
                        if( b < a ) { c = b; b = a; a = c; }
                        while( a > 1 && b%a > 1 ) {
                                c = a;
                                a = b%a;
                                b = c;
                        }
                        answer = b%a == 1 ? 1 : a;
                        break;
                case 5: 
                        a = random(2000) - 1000;
                        answer = - a - b;
                        oper = chinese_number(a) + "的相反数减去" + chinese_number(b) 
                                + (random(2) ? "是" : "等于") + "多少？";                       
                        break;
                case 6: 
                        a = random(90000) + 10000;  b = random(5) + 1;
                        answer = a;
                        for( i = 1; i < b; i ++ ) answer /= 10;
                        answer %= 10;
                        oper = chinese_number(a) + "的右边起第" + chinese_number(b) + "位数字是多少？";
                        break;
                case 7: 
                        list = users();
                        answer = 0;
                        for(i=0; i<sizeof(list); i++) {
                                if( !environment(list[i]) ) continue;
                                if( this_player() && !this_player()->visible(list[i]) ) continue;
                                answer ++;
                        }
                        oper = "现在在线的玩家个数是多少？";
                        break;
        }
        temp1 = oper;
        temp2 = "我考的范围有：" + ( (random(2)) ? "加上...." : "" ) + ( (random(2)) ? "减去...." : "" )
                + ( (random(2)) ? "乘上...." : "" ) + ( (random(2)) ? "除以...." : "" ) 
                + ( (random(2)) ? "余数...." : "" ) + ( (random(2)) ? "个位数...." : "" ) 
                + "最大公因数等等";
        if( random(2) ) temp2 = "";
        if( random(2) ) {
                oper = temp1;  temp1 = temp2;  temp2 = oper;
        }
        message_vision("\n", this_player());    // 加入一个回车，让玩家看得清楚一些
        if(temp1 != "") command("say " + temp1 );
        if(temp2 != "") command("say " + temp2 );
        command("say 请在三十秒内作答(answer)。");
        in_ask = 1;
        can_answer = 0;
        call_out("can_answer", 3);
        call_out("say_answer", 30);
        return 1;
}


void say_answer()
{
        command("say 这麽简单都不会？答案等於" + chinese_number(answer) + "。");
        in_ask = 0;     
}

void can_answer(string arg)
{
        command("say 嗯，现在可以答题了。");
        can_answer = 1;
}

int do_answer(string arg)
{
        int ans;


        if( this_player()->query("combat_exp") >= 20000 )
                return notify_fail("你已经不是小学生了。\n");
        
        if( this_player()->query_skill("literate",1) < 10 )
                return notify_fail("大字都不识一个，敢来考场献丑？先去学点(Literate)吧！\n");

        if( !in_ask ) return notify_fail("你必须等下一题。\n");
        if( !can_answer ) return notify_fail("不要着急，想清楚再答吧。\n");
        if( !arg ) return notify_fail("请你回答一个数字。\n");

        message_vision( CYN "$N答道：" + arg + "\n" NOR, this_player());
        
        if( sscanf(arg, "%d", ans)==1 ) {
                if( ans == answer ) {
                        this_player()->add_temp("robot_check", 1);
                        command("say 答对了！");
                        command("pat " + this_player()->query("id") );
                        remove_call_out("say_answer");
                        in_ask = 0;
                        can_answer = 0;
                        if( this_player()->query_temp("robot_check") >= 3 ) {
                                ans = random(5) + 5;
                                
        if( this_object()->query("get_potential") > 0 ) {
        this_object()->add("get_potential",-ans);
                                
                                this_player()->add("potential", ans );
                                write("你获得了奖励！\n");
                                write("你的潜能增加了" + chinese_number(ans) + "点。\n");
                                ans = this_player()->query("combat_exp") / 10;
                                if(ans > 20) ans = 20;
                                ans = random(ans) + 2;
                                this_player()->add("combat_exp", ans );
                                write("你的经验增加了" + chinese_number(ans) + "点。\n");
                }
                        else {
                }

                                this_player()->delete_temp("robot_check");
                        }
                        delete_temp("wrong");
                } else {
                        command("say 错！");
                        add_temp("wrong/" + this_player()->query("id"), 1);
                        if( query_temp("wrong/" + this_player()->query("id")) > 5 ) {
                                command("say " + this_player()->name() + "你再给我乱猜啊，去死吧。\n");
                                this_player()->unconcious();
                        }
                }
        }
        return 1;
}
