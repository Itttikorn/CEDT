package disease;

import util.R0;
import util.SevereLevel;

public class Covid19 extends Hypopnea {
    private R0 reproductionNumber;
    private String countryOfFirstAppearance;

    public Covid19() {
        setCountryOfFirstAppearance("China");
        setReproductionNumber(new R0(2, 3));
    }

    public R0 getReproductionNumber() {
        return reproductionNumber;
    }

    public void setReproductionNumber(R0 reproductionNumber) {
        this.reproductionNumber = reproductionNumber;
    }

    public String getCountryOfFirstAppearance() {
        return countryOfFirstAppearance;
    }

    public void setCountryOfFirstAppearance(String countryOfFirstAppearance) {
        this.countryOfFirstAppearance = countryOfFirstAppearance;
    }

    public SevereLevel severeLevel(boolean isVaccinated) {
        if (isVaccinated) return SevereLevel.Less;
        return SevereLevel.SevereIllness;
    }

    public int minimumInfectionSpread(int n) {
        int infected = 0;
        for(int i=1;i<=n;i++){
            infected+= (int) Math.pow(getReproductionNumber().getMin(),i);
        }
        return infected;
    }

    public String toString() {
        return "Covid19";
    }
}
