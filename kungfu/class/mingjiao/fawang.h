// fawang.h for fight and get letter from FaWang

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") !=  HIG "明教" NOR){
		command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？");
		return;
	}
		else {
		command("chat 本法王又得一可塑之才，真是可喜可贺！");
		command("say 恭喜你荣升为明教护法！");
		command("recruit " + ob->query("id"));
	}
	return;
}

