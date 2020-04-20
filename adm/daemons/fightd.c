
inherit F_DBASE;

int checking(object me, object ob)
{

	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if(me->is_fighting()) {
		if ( (me->query("qi")*100 / my_max_qi) <= 80 )
		command("exert recover");
		call_out("checking", 1, me, ob);
		return 1;
	}
	if(!present(ob, environment(me))) return 1;
	if(( (int)me->query("qi")*100 / my_max_qi) <= 30 ) {
		message_vision("$N跳开几步，说道："+ RANK_D->query_respect(ob)+"武功精湛，内力深厚，"+ RANK_D->query_self(ob) +"佩服！",me);
		message_vision("$N愧道：这场比试，你赢了！",me);
		me->full();
		ob->set("quest/win",1);
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say 看来" + RANK_D->query_respect(ob) +"还得多加练习，方能在当今武林中有所作为！\n");
		me->full();
		ob->set("quest/lose",1);
		return 1;
	}
	return 1;
}