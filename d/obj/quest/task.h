void init()
{
        object ob = this_player();

        if( interactive(environment()) 
        && random(5) == 2 
        && ob->query("quest"))
        {
                tell_object(ob,this_object()->name()+"转眼就不见了！\n");
                remove_call_out("des");
                call_out("des",1);
        }
}
void des()
{
        destruct(this_object());
}
