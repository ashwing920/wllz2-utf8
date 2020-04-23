// globals.h

#ifdef __SENSIBLE_MODIFIERS__
#define private protected
#define static nosave
#endif


#define DB_SAVE      
#define TX_SAVE		1
#define DB_TYPE		"sqlite"
#define DB_STR(x)    "'" + replace_string(x, "'", "''") + "'"

#define SAVE_EXTENSION	__SAVE_EXTENSION__

#define QUESTH_D(x)  ("/quest/qhlist" + x)
#define QUESTS_D(x)  ("/quest/qslist" + x)
#define QUESTW_D(x)  ("/quest/qwlist" + x)
#define QUEST_D(x)   ("/quest/qlist" + x)
#define QUEST_LET    "/quest/quest_letter"

// Important directories
#define BACKUP_DIR              "/backup/"
#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/data/config/"
#define DATA_DIR                "/data/"
#define EVENT_DIR		"/event/"
#define HELP_DIR                "/help/"
#define INC_DIR                 "/include/"
#define LOG_DIR                 "/log/"
#define STORY_DIR       	"/story/"
//new daemons
#define SCHEDULE_D              "/adm/daemons/scheduled"
#define FUBEN_D                 "/adm/daemons/fubend"
#define SYSTEM_D				"/adm/daemons/systemd"
#define NUMBER_D                "/adm/daemons/numberd"
#define DATABASE_D              "/adm/daemons/databased"
// Daemons
#define ALIAS_D                 "/adm/daemons/aliasd"
#define ARMOR_D                 "/adm/daemons/armord"
#define BAN_D                   "/adm/daemons/band"
#define CHANNEL_D               "/adm/daemons/channeld"
#define COLOR_D                 "/adm/daemons/colord"
#define CHAR_D                  "/adm/daemons/chard"
#define CHINESE_D               "/adm/daemons/chinesed"
#define CHECK_D                 "/adm/daemons/checkd"
#define COMBAT_D                "/adm/daemons/combatd"
#define COMMAND_D               "/adm/daemons/commandd"
#define CONVERT_D               "/adm/daemons/convertd"
#define EMOTE_D                 "/adm/daemons/emoted"
#define ENHANCE_D		"/adm/daemons/enhanced"
#define EVENT_D			"/adm/daemons/eventd"
#define FINGER_D                "/adm/daemons/fingerd"
#define FIGHT_D			"/adm/daemons/fightd"
#define INQUIRY_D               "/adm/daemons/inquiryd"
#define LOGIN_D                 "/adm/daemons/logind"
#define LANGUAGE_D              "/adm/daemons/languaged"
#define MONITOR_D		"/adm/daemons/monitord"
#define PNAME_D                 "/adm/daemons/pnamed.c"
#define PLACE_D                 "/adm/daemons/placed.c"
#define MONEY_D                 "/adm/daemons/moneyd"
#define MQUEST_D                "/adm/daemons/mquestd"
#define RQUEST_D                "/adm/daemons/rquestd"
#define NAME_D                  "/adm/daemons/named"
#define NPC_D                   "/adm/daemons/npcd"
#define NATURE_D                "/adm/daemons/natured"
#define PIG_D                   "/adm/daemons/pigd"
#define PROFILE_D               "/adm/daemons/profiled"
#define PK_D                    "/adm/daemons/pkd"
#define REC_D    		"/adm/daemons/recommend"
#define ROOM_D			"/adm/daemons/roomd"
#define RANK_D                  "/adm/daemons/rankd"
#define SECURITY_D              "/adm/obj/securityd"
#define SCORE_D                 "/adm/daemons/scored"
#define STORY_D                 "/adm/daemons/storyd"
#define TOPTEN_D                "/adm/daemons/toptend"
#define TASK_D                  "/adm/daemons/taskd"
#define TRANS_D			"/adm/daemons/transd"
#define CRON_D                  "/adm/daemons/cron"
#define UPDATE_D                "/adm/daemons/updated"
#define VIRTUAL_D               "/adm/daemons/virtuald"
#define VRM_SERVER		"/adm/daemons/vrm_server"
#define VENDOR_D                 "/adm/daemons/vendord"
#define WEAPON_D                "/adm/daemons/weapond"

// End of appendence

#define CLASS_D(x)              ("/kungfu/class/" + x)
#define SKILL_D(x)              ("/kungfu/skill/" + x)
#define CONDITION_D(x)          ("/kungfu/condition/" + x)

// Clonable/Non-inheritable Standard Objects

#define COIN_OB                 "/clone/money/coin"
#define CORPSE_OB               "/clone/misc/corpse"
#define GOLD_OB                 "/clone/money/gold"
#define LOGIN_OB                "/clone/user/login"
#define MASTER_OB               "/adm/single/master"
#define SEC_OB			"/adm/obj/securityd"
#define MAILBOX_OB              "/clone/misc/mailbox"
#define SILVER_OB               "/clone/money/silver"
#define SIMUL_EFUN_OB           "/adm/single/simul_efun"
#define THCASH_OB               "/clone/money/thousand-cash"
#define THGOLD_OB               "/clone/money/thousand-gold"
#define USER_OB                 "/clone/user/user"
#define VOID_OB                 "/clone/misc/void"

// Inheritable Standard Objects
#define BOOK                    "/inherit/item/book"
#define BULLETIN_BOARD          "/inherit/misc/bboard"
#define NEWS_BOARD		"/inherit/misc/nboard"
#define W_BOARD                 "/inherit/misc/wboard"
#define CHARACTER               "/inherit/char/char"
#define COMBINED_ITEM           "/inherit/item/combined"
#define EQUIP                   "/inherit/misc/equip"
#define FORCE                   "/inherit/skill/force"
#define REGROOM                 "/inherit/room/regroom.c"
#define RECORDABLE_ROOM         "/inherit/recordable_room.c"
#define ITEM                    "/inherit/item/item"
#define LIQUID                  "/inherit/food/liquid"
#define MONEY                   "/inherit/item/money"
#define NPC                     "/inherit/char/npc"
#define NPC_SAVE                "/inherit/char/npcsave"
#define SELLER_SAVE             "/inherit/char/sellersave"
#define FIGHT_NPC               "/inherit/char/fight"
#define PILL                    "/inherit/medicine/pill"
#define POWDER                  "/inherit/medicine/powder"
#define ROOM                    "/inherit/room/room"
#define CHAT_ROOM               "/inherit/room/chat_room"
#define CHALLENGE_ROOM		"/inherit/room/challenge_room"
#define SKILL                   "/inherit/skill/skill"
#define PRIVATE_ROOM            "/inherit/private_room.c"

// User IDs

#define ROOT_UID                "Root"
#define BACKBONE_UID            "Backbone"

// Features

#define F_CLEAN_UP              "/feature/clean_up.c"
#define F_ACTION                "/feature/action.c"
#define F_ALIAS                 "/feature/alias.c"
#define F_APPRENTICE            "/feature/apprentice.c"
#define F_ATTACK                "/feature/attack.c"
#define F_ATTRIBUTE             "/feature/attribute.c"
#define F_AUTOLOAD              "/feature/autoload.c"
#define F_BANKER                "/feature/banker.c"
#define F_COMMAND               "/feature/command.c"
#define F_CONDITION             "/feature/condition.c"
#define F_ENCODING              "/feature/encoding.c"
#define F_DAMAGE                "/feature/damage.c"
#define F_DBASE                 "/feature/dbase.c"
#define F_DEALER                "/feature/dealer.c"
#define F_EDIT                  "/feature/edit.c"
#define F_EQUIP                 "/feature/equip.c"
#define F_FINANCE               "/feature/finance.c"
#define F_FOOD                  "/feature/food.c"
#define F_PILL                  "/feature/pill.c"
#define F_PAWN                  "/feature/pawnowner.c"
#define F_LIQUID                "/feature/liquid.c"
#define F_MASTER                "/inherit/char/master.c"
#define F_MESSAGE               "/feature/message.c"
#define F_MORE                  "/feature/more.c"
#define F_MOVE                  "/feature/move.c"
#define F_NAME                  "/feature/name.c"
#define F_SAVE                  "/feature/save.c"
#define F_SKILL                 "/feature/skill.c"
#define F_TEAM                  "/feature/team.c"
#define F_TREEMAP               "/feature/treemap.c"
#define F_VENDOR                "/feature/vendor.c"
#define F_VENDOR_SALE           "/feature/vendor_sale.c"
#define F_SSERVER               "/feature/sserver.c"
#define F_UNIQUE                "/feature/unique.c"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it
// in effect.

#undef PROFILE_COMMANDS
