package logic.card;

import application.deck.Deck;
import logic.player.Player;

import java.util.ArrayList;

public class MageCard extends BaseCard{
    private Element mageType;

    public MageCard(String name, int power, int health, Element mageType){
        super(name,power,health);
        setMageType(mageType);
    }

    public Element getMageType() {
        return mageType;
    }

    public void setMageType(Element mageType) {
        this.mageType = mageType;
    }

    @Override
    public void play(Player player) {
        int cardCount = 0;
        for(BaseCard b : player.getField()){
            if(b instanceof OrbCard){
                if(((OrbCard) b).getOrbType().equals(this.getMageType())){
                    cardCount++;
                }
            }
        }
        setPower(this.getPower() + cardCount);
    }

    @Override
    public boolean canPlay(Player player) {
        for(BaseCard b : player.getField()){
            if(b instanceof OrbCard){
                if(((OrbCard) b).getOrbType().equals(this.getMageType())){
                    return true;
                }
            }
        }
        return false;
    }
}
