         // 昆仑派的弟子
inherit NPC;
#define SET_SKILL   50           // 定义基本武功的值，自动生成经验
#define SPE_SKILL   40            // 定义特殊武功的值

string *first_name = ({ "郑","王","张","陈","金","姑苏","钱","孙","李","周","吴",
        "刘","林" });
string *name_words = ({ "志","忠","良","志","忠","大","彦","良","勇","元","华","宏",
        "孝","雄","龙","明","文","武","斌","来","胜","进","铭","彬","东","伟" });
string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *name_wordss = ({ "英","媚","珍","华","盈","小","红","婷","娴","小","娩","妙",
        "娟","如","絮","妲","妮","妹","姑","娥","娜","媸","妯","芳","芬","香" });

void create()
{
        string name, id;
        name = first_name[random(sizeof(first_name))];

        if (random(3)>1){
             set("gender", "男性");
             name += name_words[random(sizeof(name_words))];
             if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
        }else{
             set("gender", "女性");
             name += name_wordss[random(sizeof(name_wordss))];
             if( random(10) > 2 ) name += name_wordss[random(sizeof(name_wordss))];
        }
        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
        set_name(name, ({ id+" dizi", "dizi" }) );
        set("age", random(10)+14);
        set("long", name+"刚拜师学艺不久，满脸稚气。\n");               
        set("attitude", "peaceful");
        set("str", 25);

        set("int", random(20)+2);
        set("con", random(20)+2);
        set("str", random(20)+2);
        set("dex", random(20)+2);

        set("jingli",1000);
        set("max_jingli",200);
        set("neili", 900);
        set("max_neili", 500);
        set("jiali",300);
        set("combat_exp",SET_SKILL*SET_SKILL*SET_SKILL/10);
 
        set_skill("force",   SET_SKILL);
        set_skill("sword",   SET_SKILL);
        set_skill("unarmed", SET_SKILL);
        set_skill("parry",   SET_SKILL);
        set_skill("dodge",   SET_SKILL);
        set_skill("literate",SET_SKILL);

        set_skill("xuantian-force",SPE_SKILL);
        set_skill("zhengliangyi-sword", SPE_SKILL);
        set_skill("yaoming-dodge", SPE_SKILL);
        set_skill("sanyin-unarmed",SPE_SKILL);
        
        map_skill("dodge", "yaoming-dodge");
        map_skill("force", "xuantian-force");
        map_skill("parry", "zhengliangyi-sword");
        map_skill("sword", "zhengliangyi-sword");
        map_skill("unarmed","sanyin-unarmed");   
 

        create_family("昆仑派", 16, "弟子");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/sword")->wield();
}

