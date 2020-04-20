
#include <ansi.h>

string convert_color( string str)
{
	if(!str) return "";

	str = replace_string(str, "$BLK$", BLK);
	str = replace_string(str, "$RED$", RED);
	str = replace_string(str, "$GRN$", GRN);
	str = replace_string(str, "$YEL$", YEL);
	str = replace_string(str, "$BLU$", BLU);
	str = replace_string(str, "$MAG$", MAG);
	str = replace_string(str, "$CYN$", CYN);
	str = replace_string(str, "$WHT$", WHT);
	str = replace_string(str, "$HIR$", HIR);
	str = replace_string(str, "$HIG$", HIG);
	str = replace_string(str, "$HIY$", HIY);
	str = replace_string(str, "$HIB$", HIB);
	str = replace_string(str, "$HIM$", HIM);
	str = replace_string(str, "$HIC$", HIC);
	str = replace_string(str, "$HIW$", HIW);
	str = replace_string(str, "$NOR$", NOR);

	str = replace_string(str, "$BBLK$", BBLK);
	str = replace_string(str, "$BRED$", BRED);
	str = replace_string(str, "$BGRN$", BGRN);
	str = replace_string(str, "$BYEL$", BYEL);
	str = replace_string(str, "$BBLU$", BBLU);
	str = replace_string(str, "$BMAG$", BMAG);
	str = replace_string(str, "$BCYN$", BCYN);
	str = replace_string(str, "$BWHT$", BWHT);

	str = replace_string(str, "__$__", "$");

	return str;
}
string clean_color(string str)
{
	str = replace_string(str, "$BLK$","");
	str = replace_string(str, "$RED$","");
	str = replace_string(str, "$GRN$","");
	str = replace_string(str, "$YEL$","");
	str = replace_string(str, "$BLU$","");
	str = replace_string(str, "$MAG$","");
	str = replace_string(str, "$CYN$","");
	str = replace_string(str, "$WHT$","");
	str = replace_string(str, "$HIR$","");
	str = replace_string(str, "$HIG$","");
	str = replace_string(str, "$HIY$","");
	str = replace_string(str, "$HIB$","");
	str = replace_string(str, "$HIM$","");
	str = replace_string(str, "$HIC$","");
	str = replace_string(str, "$HIW$","");
	str = replace_string(str, "$NOR$","");

	str = replace_string(str, BLK, "");
	str = replace_string(str, RED, "");
	str = replace_string(str, GRN, "");
	str = replace_string(str, YEL, "");
	str = replace_string(str, BLU, "");
	str = replace_string(str, MAG, "");
	str = replace_string(str, CYN, "");
	str = replace_string(str, WHT, "");
	str = replace_string(str, HIR, "");
	str = replace_string(str, HIG, "");
	str = replace_string(str, HIY, "");
	str = replace_string(str, HIB, "");
	str = replace_string(str, HIM, "");
	str = replace_string(str, HIC, "");
	str = replace_string(str, HIW, "");
	str = replace_string(str, NOR, "");
	str = replace_string(str, BLINK, "");
	str = replace_string(str, ESC+"[0;37;0m", "");
	str = replace_string(str, ESC+"[0m","");
	str = replace_string(str,"[57;44m","");
	str = replace_string(str,"[51m","");
	str = replace_string(str,"[52m","");
	str = replace_string(str,"[53m","");
	str = replace_string(str,"[54m","");
	str = replace_string(str,"[55m","");
	str = replace_string(str,"[56m","");
	str = replace_string(str,"[57m","");
	str = replace_string(str,"[0m","");
	str = replace_string(str,"[2;37;0m","");
	str = replace_string(str, BOLD,"");

	//BackGround Color
	str = replace_string(str, BWHT, "");
	str = replace_string(str, BBLK, "");
	str = replace_string(str, BRED, "");
	str = replace_string(str, BGRN, "");
	str = replace_string(str, BYEL, "");
	str = replace_string(str, BBLU, "");
	str = replace_string(str, BMAG, "");
	str = replace_string(str, BCYN, "");
	
	str = replace_string(str, "$BBLK$", "");
	str = replace_string(str, "$BRED$", "");
	str = replace_string(str, "$BGRN$", "");
	str = replace_string(str, "$BYEL$", "");
	str = replace_string(str, "$BBLU$", "");
	str = replace_string(str, "$BMAG$", "");
	str = replace_string(str, "$BCYN$", "");
	str = replace_string(str, "$HBRED$", "");
	str = replace_string(str, "$HBGRN$", "");
	str = replace_string(str, "$HBYEL$", "");
	str = replace_string(str, "$HBBLU$", "");
	str = replace_string(str, "$HBMAG$", "");
	str = replace_string(str, "$HBCYN$", "");

	return str;
}
