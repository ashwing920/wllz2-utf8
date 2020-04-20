// bookd_item.c

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

int is_book() { return 1;}

void setup(){ }

string long()
{
        string name = query("name");
        string bc = "$BBLU$";
        string lc = "$WHT$";
        string fc = "$BWHT$";
        string tc = "$BLK$";
        string str;
        int i, t;

        if( query("bcolor") ) bc = query("bcolor");     // 书的整体颜色
        if( query("lcolor") ) lc = query("lcolor");     // 书的装订线颜色
        if( query("fcolor") ) fc = query("fcolor");     // 书的标题框颜色
        if( query("tcolor") ) tc = query("tcolor");     // 书的标题颜色

        name = replace_string(name, "《", "");          // 清除书名两边的书括号
        name = replace_string(name, "》", "");
        name = replace_string(name, "「", "");
        name = replace_string(name, "」", "");
        name = replace_string(name, "『", "");
        name = replace_string(name, "』", "");
        t = strlen( name );
        switch( t / 2 ) {
                case 1 :
                        return  "\n" BBLK + space( 17 ) + NOR "\n"
                                BBLK + space( 4 ) + bc + lc + "        H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + " " + fc + "  " + bc + lc + "     H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + " " + fc + tc + sprintf( "%c%c", name[0], name[1] ) + bc + lc + "     H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + " " + fc + "  " + bc + lc + "     H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "        H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "        H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "        H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 17 ) + NOR "\n";
                case 2 :
                        return  "\n" BBLK + space( 19 ) + NOR "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + "  " + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[0], name[1] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[2], name[3] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + "  " + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 19 ) + NOR "\n";
                case 3 :
                        return  "\n" BBLK + space( 19 ) + NOR "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + "  " + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[0], name[1] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[2], name[3] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[4], name[5] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + "  " + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 19 ) + NOR "\n";
                case 4 :
                        return  "\n" BBLK + space( 19) + NOR "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[0], name[1] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[2], name[3] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[4], name[5] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[6], name[7] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 19 ) + NOR "\n";
                case 5 :
                        return  "\n" BBLK + space( 19 ) + NOR "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[0], name[1] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[2], name[3] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[4], name[5] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[6], name[7] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "  " + fc + tc + sprintf( "%c%c", name[8], name[9] ) + bc + lc + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + "          H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 19 ) + NOR "\n";
                default:
                        for( i = 0, str = ""; i < t; i ++ ) str += " ";
                        return  "\n" BBLK + space( strlen( str ) + 15 ) + NOR "\n"
                                BBLK + space( 4 ) + bc + lc + str + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + "   " + fc + tc + name + bc + lc + "   H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + str + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + str + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( 4 ) + bc + lc + str + "      H" BBLK + space( 4 ) + NOR + "\n"
                                BBLK + space( strlen( str ) + 15 ) + NOR "\n";
        }
}
