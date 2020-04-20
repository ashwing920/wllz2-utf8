// Room: /d/shaolin/beilin3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "地下室");
        set("long", @LONG
这里是佛塔底下的地下密室。密室虽小，却也五脏俱全，石桌石椅，
石几石床，连室内放的几件器皿，也都是石制的。看来似乎很久以前有人
在这里住过。正中的石桌上平放着一块薄薄的石板，上面好象刻着些什么。
LONG
);
        set("objects",([
                "/clone/book/book-stone" : 1,
        ]));
        setup();
}
