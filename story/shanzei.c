// story:shanzei

#include <ansi.h>

string give_gift();

string prompt() {
        return HIM"【江湖风云】"NOR;
}
private mixed *story = ({
        "黑山寨中，大小喽罗们正议论纷纷，原来是寨主三十大寿就快到了，正准备着给寨主送礼呢。",
        "喽罗甲：嘿，你说给咱寨主送什么好呀？",
        "喽罗乙：咱大王喜欢金银珠宝，稀世宝物，咱投其所好呗！",
        "喽罗丙急了：我哪来这些稀世宝物，家里都穷的揭不开锅了才丢下锄头做山贼的耶 . . .",
        "喽罗头：嘿！要是你送的贺礼讨得咱大王开心，说不定大王还赏你个封号。",
        "喽罗甲：老大，俺上有八十岁老母，下有三岁小儿，俺上哪找去啊 . . . ",
        "喽罗乙：9494 ...",
        "喽罗丙：哎，看来做山贼也是做个穷山贼，我的天哟，什么命这么苦啊。",
        "喽罗头：嗯 . . . . . ",
        "喽罗甲：老大，你可得为我们兄弟几个做主呀，兄弟几个往后的日子就看您的了。",
        "喽罗乙：9494 ...",
        "喽罗丙：9494 ...",
        "喽罗头想了想：嗯，这样吧，咱兄弟几个下山走一遭，搜刮点东西不就得了吗？",
        "喽罗甲：老大！咱兄弟几个听你的就是。",
        "喽罗乙：9494 ...",
        "喽罗丙：9494 ...",
        "喽罗头：好，有福同享，有难同当，兄弟们抄上随身家伙，下山去！",
        (: give_gift :)
});
private void create(){ seteuid(getuid());}
mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
string give_gift()
{
        STORY_D->give_gift("/clone/npc/shanzei",5,HIM "\n黑山寨喽罗走了过来。\n\n" NOR);
        return CHANNEL_D->do_channel(this_object(),"rumor", "听说黑山寨的喽罗们下山烧杀抢掠来啦！！");
}
