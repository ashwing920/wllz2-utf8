 // liquid.c

int is_liquid() { return 1;}
string extra_long()
{
        int amount, max;
        string str;
        object ob = this_object();
        
        if( amount = ob->query("liquid/remaining") ) {
                max = ob->query("max_liquid");
                if( amount == max )
                        str = "里面装满了" + ob->query("liquid/name") + "。\n";
                else if( amount > max/2 )
                        str = "里面装了七、八分满的" + ob->query("liquid/name") + "。\n";
                else if( amount >= max/3 )
                        str = "里面装了五、六分满的" + ob->query("liquid/name") + "。\n";
                else if( amount > max/4 )
                        str = "里面装了少许的" + ob->query("liquid/name") + "。\n";
                return str;
        }
        else return 0;
}
