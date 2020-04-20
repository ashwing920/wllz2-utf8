// moneyd.c  钱的功能

//#pragma optimize
//#pragma save_binary

string price_str(int amount)
{
	string output;

	if (amount < 1) amount = 0;

	output = "";
	if (amount / 10000) {
		output = chinese_number(amount / 10000) + "两黄金";
		amount %= 10000;
	}
	if (amount / 100) {
		output += chinese_number(amount / 100) + "两白银";
		amount %= 100;
	}
	if (amount) output += chinese_number(amount) + "文铜板";
	if (output == "") output = "无法判断价值";

	return output;
}

string money_str(int amount)
{
	if (amount < 1) amount = 1;

	return price_str( amount );
}

void pay_player(object who, int amount)
{
	object ob;

	seteuid(getuid());

	if( amount < 1 ) amount = 1;
	if( amount/10000000 ) {
		ob = new(THGOLD_OB);
		ob->set_amount(amount/10000000);
		ob->move(who,1);
		amount %= 10000000;
	}
	if( amount/100000 ) {
		ob = new(THCASH_OB);
		ob->set_amount(amount/100000);
		ob->move(who,1);
		amount %= 100000;
	}
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who,1);
		amount %= 10000;
	}
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who,1);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who,1);
	}
}
int can_afford(object who, int amount)
{
	object tg_ob, tc_ob, g_ob, s_ob, c_ob;
	int tgc, tcc, gc, sc, cc;

	seteuid(getuid());

	if (tg_ob = present("thousand-gold", who))
		tgc = tg_ob->query_amount();
	else
		tgc = 0;
	if (tc_ob = present("thousand-cash", who))
		tcc = tc_ob->query_amount();
	else
		tcc = 0;
	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;

	if (cc + sc * 100 + gc * 10000 + tcc * 100000 + tgc * 10000000 < amount)  return 0;
	else return 1;
}
int player_pay(object who, int amount)
{
	object tg_ob, tc_ob, g_ob, s_ob, c_ob;
	int tgc, tcc, gc, sc, cc, left;

	seteuid(getuid());

	if (tg_ob = present("thousand-gold", who))
		tgc = tg_ob->query_amount();
	else
		tgc = 0;
	if (tc_ob = present("thousand-cash", who))
		tcc = tc_ob->query_amount();
	else
		tcc = 0;
	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;

	if(tgc > 100) tgc = 100;
	if(tcc > 10000) tcc = 10000;

	if (cc + sc * 100 + gc * 10000 + tcc * 100000 + tgc * 10000000 < amount)
		return 0;
	else {
		left = cc + sc * 100 + gc * 10000 + tcc * 100000 + tgc * 10000000 - amount;
		tgc = left / 10000000;
		left %= 10000000;
		tcc = left / 100000;
		left %= 100000;
		gc = left / 10000;
		left %= 10000;
		sc = left / 100;
		cc = left % 100;

		if (tg_ob) {
			if(tgc <= 0) destruct(tg_ob);
			else tg_ob->set_amount(tgc);
		}
		else if (tgc) {
			tg_ob = new(THGOLD_OB);
			tg_ob->set_amount(tgc);
			tg_ob->move(who,1);
		}
		if (tc_ob) {
			if(tcc <= 0) destruct(tc_ob);
			else tc_ob->set_amount(tcc);
		}
		else if (tcc) {
			tc_ob = new(THCASH_OB);
			tc_ob->set_amount(tcc);
			tc_ob->move(who,1);
		}
		if (g_ob) {
			if(gc <= 0) destruct(g_ob);
			else g_ob->set_amount(gc);
		}
		else if (gc) {
			g_ob = new(GOLD_OB);
			g_ob->set_amount(gc);
			g_ob->move(who,1);
		}
		if (s_ob) {
			if(sc <= 0) destruct(s_ob);
			else s_ob->set_amount(sc);
		}
		else if (sc) {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who,1);
		}
		if (c_ob) {
			if(cc <= 0) destruct(c_ob);
			else c_ob->set_amount(cc);
		}
		else if (cc) {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who,1);
		}

		return 1;
	}
}


