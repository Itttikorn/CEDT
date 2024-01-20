package disease;

import util.R0;
import util.SevereLevel;

public class Delta extends Covid19{
    private int spikeProtein;

    public int getSpikeProtein() {
        return spikeProtein;
    }

    public void setSpikeProtein(int spikeProtein) {
        this.spikeProtein = spikeProtein;
    }

    public Delta(){
        setReproductionNumber(new R0(5,7));
        setCountryOfFirstAppearance("India");
        setSpikeProtein(10);
    }

    public SevereLevel severeLevel(boolean isVaccinated){
        if(isVaccinated) return SevereLevel.MildOrLess;
        return SevereLevel.SevereIllness;
    }

    public int minimumInfectionSpread(int n){
        //ไม่แน่ใจว่า how much code you can re-use คือลบอันนี้ออกไปได้เลยรึเปล่า
        int infected = 0;
        for(int i=1;i<=n;i++){
            infected+= (int) Math.pow(getReproductionNumber().getMin(),i);
        }
        return infected;
    }

    public String toString(){
        return "Delta";
    }
}
