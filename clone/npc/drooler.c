// drooler.c - 桃谷六仙

#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "你知道武林列传主页地址吗？http://www.mud.nanhai.net",
        "你知道武林列传有5个端口可以登陆吗？2000,2001,2002,2003,2004",
        "这里的人都不理我！",
        "你可以和我说一会儿话吗？",
        "你陪我说话，我教你武功。好不好？",
        "我有办法帮你改高武功....",
        "我给你发了一封信，你收到了吗？",
        "我在假装桃谷六仙耶。",
        "嘻嘻，我不是真的桃谷六仙耶。",
        "有谁可以给我一些钱？",
        "你可以给我一些吃的东西吗？",
        "我见过你耶。",
        "我认得你耶。",
        "Hi, 我们又见面啦！",
        "Hi",
        "Hello",
        "wait....",
        "这里的人都死光了吗？",
        "这里全都是机器人呀？怎么没人说话？",
});

varargs void drool(string msg, string who);

void create()
{
        set_name("桃谷六仙", ({ "taogu liuxian", "taogu", "liuxian", "drooler" }));
        set("long", @LONG
桃谷六仙，用很天真的眼神看着你。
LONG
);
        set("attitude", "friendly");
        set("title", "天下第一大嘴");
        set("gender", "男性");
        set("age", 40);
        set("str", 30);                         // 膂力
        set("cps", 20);                         // 定力
        set("cor", 20);                         // 胆识
        set("per", 10);                         // 容貌
        set("con", 30);                         // 根骨

        set("combat_exp",210000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: command, "get all" :),
                (: command, "wear all" :),      // (: command, "wield all" :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();     // 装备
        add_money("gold", 1);                           // 金钱

        if( clonep() ) CHANNEL_D->register_relay_channel("chat","wllz","rumor");
}


int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "\n", "");
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "吗", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");
        msg = replace_string(msg, "嘛", "");
        msg = replace_string(msg, "喔", "");
        msg = replace_string(msg, "哦", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who;

        if( !userp(ob)
        || (channel != "chat" && channel != "rumor"
        && channel != "music" && channel != "wllz" )) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who;

        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )  drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                if( random(10)<5 ) {
                        command("say 为什么踢我？会痛耶！");
                        break;
                }
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "为什么") >= 0) ) {
                if( sscanf(msg, "%*s为什么%s", msg)==2 ) msg = "为什么" + msg;
                switch(random(8)) {
                case 0: command("say " + who + "，你是在问我吗？"); break;
                case 1: command("say 关於" + msg + " ... "); break;
                case 2: command("say 呃 ... "); drool(); break;
                case 3: command("say 这个问题嘛 ...."); break;
                case 4: command("say " + who + "，知道这个问题的答案对你那么重要吗？"); break;
                case 5: command("say " + msg + "？"); break;
                case 6: command("say " + who + "你能不能说清楚一点？"); break;
                case 7: command("say " + who + "，我不懂你问的问题"); break;
                }
        }
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "您") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "您", "我");
                switch(random(11)) {
                case 0: command("say " + who + "，你是说" + msg + "吗？");      break;
                case 1: command("say 你确定" + msg + "？");     break;
                case 2: command("say " + msg + "跟你有什么关系？");     break;
                case 3: command("say 嗯 ... " + who + "说得好。"); break;
                case 4: command("say " + who + "你为什么对" + msg + "这么有兴趣？"); break;
                case 5: command("say 为什么你认为" + msg + "？"); break;
                case 6: command("say 换个话题吧。"); drool(); break;
                case 7: command("say 才怪。"); break;
                case 8: command("say 好笑！"); break;
                case 9: command("say 有这个可能 ...."); break;
                case 10: command("say 不是吧？！有这样的事？"); break;
                }
        }
        else if( (strsrch(msg, "我") >= 0)) {
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("hmm"); break;
                case 1: command("say 你是说" + msg + "吗？");   break;
                case 2: command("say 真的？" + msg + "？");     break;
                case 3: command("say 如果" + msg + "，我能帮你什么忙吗？");     break;
                case 4: command("say 你认为" + msg + "？"); break;
                case 5: command("say 我有同感。"); break;
                case 6: command("say 你说的「" + msg + "」我不能苟同。"); break;
                case 7: command("say 有关「" + msg + "」的话题到此为止好吗？"); break;
                }
        } else {
                switch(random(14)) {
                        case 0: command("?"); break;
                        case 1: command("hmm"); break;
                        case 2: command("grin"); break;
                        case 3: command("smile"); break;
                        case 4: command("say 为什么说" + msg + "？"); break;
                        case 5: command("say 「" + msg + "」是什么意思？"); break;
                        case 6: command("say " + msg + "？"); break;
                        case 7: command("say ...."); break;
                        case 8: command("say "+ msg +"！！"); break;
                        case 9: command("say 你怎么知道" + msg + "？"); break;
                        case 10: command("say 刚刚" + who + "不是说了，" + msg); break;
                        case 11: command("say 我当然知道，" + msg); break;
                        case 12: command("say 然後呢？"); break;
                        case 13: command("say 真的吗？"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
int accept_object()
{
        return 1;
}
