#!/system/bin/sh    
       # cekhing ID shell 
    if [ "$(id -u)" -ne 2000 ]; then
       echo "[Eror | @Yeye_nat(Yeye) ]"
      exit 1
         fi
    # check arry derktory
  if [ -d /sdcard/Shell-Yeye ]; then
    echo "derktory Not found !"
   fi > /dev/null 2>&1
   # smart Notification
      shell() {
      semart="$1"
    cmd notification post -S bigtext -t '🍃 Never line' 'Tag' "$semart" > /dev/null 2>&1
  }
   
   # styal display Terminal
  shell "Loading Program...."
  echo 
  echo
  echo "     ☆================================☆"
  echo
  echo "       ~ Discription Never line....."
  echo
  echo "       - Author              :  @Yeye_nat"
  echo "       - Version             :  1.0"
  echo "       - Release            :  09 - Jan -2025"
  echo "       - Name Shell      :  Never line"
  echo     
  echo "    |_______________________________________|"
  echo "    \______________________________________/"
 sleep 1    
   cp /sdcard/Shell-Yeye/svc /data/local/tmp/svc && chmod +x /data/local/tmp/svc && /data/local/tmp/svc