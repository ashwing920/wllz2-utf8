//aliasd.c
// Design By robert 蝴蝶君 email:robert_st@sina.com

//#pragma optimize
//#pragma save_binary

mapping global_alias = ([
	"l":    "look",
	"n":    "go north",
	"e":    "go east",
	"w":    "go west",
	"s":    "go south",
	"nu":   "go northup",
	"eu":   "go eastup",
	"wu":   "go westup",
	"su":   "go southup",
	"nd":   "go northdown",
	"ed":   "go eastdown",
	"wd":   "go westdown",
	"sd":   "go southdown",
	"ne":   "go northeast",
	"se":   "go southeast",
	"nw":   "go northwest",
	"sw":   "go southwest",
	"u":    "go up",
	"d":    "go down",
	"i":    "inventory",
	"sc":   "score",
	"dazuo": "exercise",
	"du":   "study",
	"tou":   "steal",
	"xue":   "learn",
	"cha":   "skills",
	"bai":   "apprentice",
	"bei":   "prepare",
	"kaichu": "expell",
	"tuna":   "respirate",
	"jiali":  "enforce",
	"jifa":   "enable",
	"lian":   "practice",
	"quanjia": "persuade",
	"yanjiu": "research",
	"yong":   "perform",
	"yun":  "exert",
	"fangqi": "abandon",
	"sha":  "kill",
	"chi": "eat",
	"he": "drink",
	"zhuang":"fill",
	"gei": "give",
	"na": "get",
	"diu": "drop",
]);

string process_global_alias(string arg)
{
	string *word;

	if (arg[0]=='\'') return "say " + arg[1..strlen(arg)-1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}
