MUDB?畼^鲬廬� include/globals.h include/action.h include/ansi.h include/command.h include/condition.h include/dbase.h include/move.h include/name.h include/skill.h include/team.h include/user.h  inherit/char/char.c   璞U        h   /   `琓 琓����,  �	  �  �  �  �  �  �  �  �     F          �  J
 M %   �.-牌�@
^

~^?#\+�   .]<h$ <
h .+  ]<�% <l % 肂�: 肂B]�/$ �/$ �/% +�  %
 � h +�  <�% <穐%
 � + �  �  � 
 � <�% � % 
 h+ �l, 
�A ^^^l- �!  "肂2$	 #肂2 +�  .$肂2$	 %肂2) <l 
 +�   +�  <h$	 <l h .+   +  .r +O  %Z &+ =Z�%M 罖4%E <
' h%6 <
( h%' $肂
d`)肂a<1$ %肂
d`*肂a<1 +,� +[  <篽% <l  �- < .@= Z># . 繣^

~^?#\+�  ]< .翨c$ +�  h% +O  h% <穐' 
 
乚 <俔<% <穐 < ��. <� .<��   �/B .� -�0 ]< �1 ]2+ ]< 3A+ ]<> < � .< � .篽% +O   -铝4$ < / -0+  -.�  +�   -2+  -.-.< ?$\.]< h% 4+ =Zz <z_<B]c + 5^6+ ^7^]8+ =Z�
 8+ ]9+ =Z :耝;^<^]<	 撩^] < �<^<^]<  >$ +  >$^] <-� 	 =胇]<穐% <� +  >=P- ?=P-@+�  A=[B+�  C=[D+�  E=[+O   F=[� G=[<l h% H+  IH+ ^J^^=[� K=[�% �
x4 L=[<-.,  ,"  ,  ,#  ,  ,  ?$\.   h匨 C        H圡 F)       H螹 D       罔M  ;      x頜 H5      X+O G�      X餞 E       萂U          鐼U          kM I�               	   
            
  	                                             
  	                      
  	                                
  	                                
  	                      
  	                        	   
            
  	                      
  	                      
  	                      
  	                       
  	                      
  	                            	 C  
 �  	
�������������� !"#$%&'�����()*+,-./012345678�����������������9:;<=>?@ABCDEFGHI��������JKLMNOPQRSTU������������VWXYZ[\]^_`abcdefg��������������������������������������hijklmnopqrs������tuvwxyz{|}~�����€亗儎厗噲墛�������������實帍悜挀敃枟������櫄洔潪煚、￥��������������ウЖ┆���   @    @    @  @@@@ @@@ @5@   	555    5 5 5 . 5@5 5 5 . 5@5 5      5 5 5 . 5@5 5 5 . 5@5 5 5 5@5@5@5    @@            5 5 5 . 5@5 5 5 . 5@5 5 5 5@5@5@5         5 5 5 . 5@5 5 5 . 5@5 5     5 5 5 . 5@5 5 5 . 5@5 5 5@55@555     @@   @     @  5  @5@5 5 5 5 5@5 5 5     5 5 5 . 5@5 5 5 . 5@5 5   5    5 5 5 . 5@5 5 5 . 5@5 5      5 5 5 . 5@5 5 5 . 5@5 5  55@  5 5 5 . 5@5 5 5 . 5@5 5    5@$@5@5 5 5 . 5@5 5 5 . 5@5 5     5@@5  5@ 5  5@ 5 5 5 . 5@5 5 5 . 5@5 5        5@        璞Ux^M�6Ux扢坙U窣U∟U�U(鮑榤Nh鬠�UHU(騏X%O疶桄T笌M騏鑰U豗T栉M桉U锐UX甌�U厣MH馯�U热M仞U�M葛U鍹8OO鑡N€NhET枨M樓MXO�O鎁橉Ux餟X餟8餟╕T貜M橆MH誑X頜X�乳M8�‵T8頜頜88O竜M�M桧Mx鞰8OH鞰HlT鞰鑆N桁M胳M堨M鑄U讣M�$OX霱坈T劝UH騏郼U     U�<U&    U€^�*    U€�;    U犌]    U劳v    U癋U�    U ��    U饖��    U俺U�    U鄿U�    Up��    U愮�    U措�    U`燯   U酗   U痼-!   U                                                                                                                                                                                                                                                                                                                                                                                                                 feature/action.c feature/alias.c feature/apprentice.c feature/attack.c feature/attribute.c feature/command.c feature/condition.c feature/damage.c feature/dbase.c feature/edit.c feature/finance.c feature/message.c feature/more.c feature/move.c feature/name.c feature/skill.c feature/team.c inherit/char/char.c include/globals.h include/action.h include/ansi.h include/command.h include/condition.h include/dbase.h include/move.h include/name.h include/skill.h include/team.h include/user.h /adm/daemons/chard
 setup_char env prompt time mud hp is_attach_system biguan
 query_temp breakup closed is_ghost death queryI [1;34m黑暗中一个声音怒喝道：你一个孤魂野鬼，跑上来阳间做什么？
[2;37;0m4 [1;34m
天空中突然出现一个黑洞，一股阴冷刺骨地寒风将 name 卷了进去。

 [2;37;0m /d/death/gate move eff_qi eff_jing qi jing	 env/wimpy
 fight_room watch_fight_room max_qi max_jing /cmds/std/go do_flee scan
 update_age	 user_dump env/invisibility apply/shade_vision apply/astral_vision
 perception apply/short ( id ) title nickname 「 」   [1;34m(鬼气) [2;37;0m [1;31m <闭关中>[2;37;0m [1;32m <断线中>[2;37;0m killer [1;31m <逃亡中>[2;37;0m parsion [1;31m <服刑中>[2;37;0m drunk [1;36m <醉酒中>[2;37;0m [1;31m <战斗中>[2;37;0m [1;36m <输入文字中>[2;37;0m disable_type [1;31m  [1;33m <编辑档案中>[2;37;0m [1;35m <发呆中>[2;37;0m tick
 short_desc create
 heart_beat is_character short set_short_desc visible setup set_temp_vector
 set_vector #global_init#��0    �        M        	        
     	    
   
      �  ����������	����������	��	��������	��������	����������� 



#	$%,467:;<=?@BEGHJ
LMO	Q	RT	WX	Z[	]^`acdfgijlm-o  