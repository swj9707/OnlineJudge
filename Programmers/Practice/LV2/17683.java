package LV2;

class Solution {
    public String solution(String m, String[] musicinfos) {
        int maxPlaytime = -1;
        m = changeString(m);
        String answer = "";
        for (String music : musicinfos) {

            String[] info = music.split(",");

            int startTime = Integer.parseInt(info[0].split(":")[0]) * 60 + Integer.parseInt(info[0].split(":")[1]);
            int endTime = Integer.parseInt(info[1].split(":")[0]) * 60 + Integer.parseInt(info[1].split(":")[1]);
            int playTime = endTime - startTime;

            String title = info[2];
            String musicString = changeString(info[3]);

            if (playTime > musicString.length()) {
                StringBuilder fullMusic = new StringBuilder();
                for (int i = 0; i < playTime / musicString.length(); i++) {
                    fullMusic.append(musicString);
                }
                fullMusic.append(musicString.substring(0, playTime % musicString.length()));
                musicString = fullMusic.toString();
            } else {
                musicString = musicString.substring(0, playTime);
            }

            if (musicString.contains(m) && playTime > maxPlaytime) {
                answer = title;
                maxPlaytime = playTime;
            }

        }

        return maxPlaytime != -1 ? answer : "(None)";
    }

    public String changeString(String data) {
        data = data.replace("C#", "c");
        data = data.replace("D#", "d");
        data = data.replace("F#", "f");
        data = data.replace("G#", "g");
        data = data.replace("A#", "a");
        return data;
    }
}