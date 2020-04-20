// story:shanzei

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "崎岖的山道上，一群手持长剑的尼姑正结伴而行，走在前面的，正是恒山派的掌门人定逸师太。",
        "定逸师太：此地地形凶险，大家提高警惕，加快脚步，前面就是廿八铺了。",
        "众尼姑应道：是！",
        "此时，早已埋伏在廿八铺的刺客们，远远已经看见人群前来，纷纷蒙上了面巾. . .",
        "突然，定逸师太脸色一变，眼睛紧紧的盯着前方 . . .",
        "定逸师太轻轻回过头，对身后的仪琳说道：小心！前面有埋伏，你在这里保护众师妹。",
        "话音刚落，只见定逸师太手中长剑飞鞘而出，纵身跃起，朝屋顶的一个黑影飞了过去。",
        "谁知那黑影霎时“嗖”的一声，犹如鬼魅一般，飘开数丈之远，沿着房顶迅速逃开。",
        "定逸师太喝道：狗贼莫跑，留下性命来～～～，说完朝那黑影追了过去。",
        "仪琳一脸惊惶，大叫道：师父～～师父～～～～，飞奔着追着定逸师太。",
        "刚跑开不远，只看到，“嗖嗖嗖”的数十个黑影中屋顶跳了下来。",
        (: give_gift :)
});
private void create(){ seteuid(getuid());}
mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
string give_gift()
{
        object obj;
        int i,n;
        n = random(10) + 5;

        for(i=0;i<n;i++){
        	obj = new("/clone/npc/nigu");
        	obj->move("/d/fuzhou/erbapu");
        }
        for(i=0;i<n;i++){
        	obj = new("/clone/npc/songshandizi");
        	obj->move("/d/fuzhou/erbapu");
        }
        return CHANNEL_D->do_channel(this_object(),"rumor","听说恒山派弟子在廿八铺遭到黑衣人的伏击！");
}
