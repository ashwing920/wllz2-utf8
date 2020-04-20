// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /city3/tidufu.c

inherit ROOM;

void create()
{
	set("short", "提督府");
	set("long", @LONG
这里便是提督大人办公事的地方。正前方 (front)大红楠木案桌后正
经端坐着的，就是成都提督吴天德。两边站立纹风不动的是他的亲兵侍从
，看上去都十分彪悍。
LONG
);
	set("exits",([
		"south" : __DIR__"tidugate",
	]));
	set("objects",([
		__DIR__"npc/wutiande" : 1,
		__DIR__"npc/shicong"  : 2,
		__DIR__"npc/qinbing" : 4,
	]));
	set("item_desc",([
		"front" : "
		###########################
		#			 #
		#	民   安   境   靖	#
		#			 #
		###########################
				!~A~!
			  @~~~~~!(O)!~~~~~@
			   (.@ @.)
				. ~ .
			 /   ~.你奶奶的...你这刁民...还瞧甚麽? 不认得老爷麽? ...
			#	   #
		 HHHH	 #		   #
		 HHHH   #	n	 n	#
	  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
	   ```````````````````````````````````````
		  ()			  ()
		 ()			()
		()			  ()
		   ()				()\n"
	]));

	setup();
	replace_program(ROOM);
}
