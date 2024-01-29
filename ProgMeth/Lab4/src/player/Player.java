package player;

import item.armor.Boots;
import item.armor.Helmet;
import item.armor.Suit;
import item.base.BaseArmor;
import item.base.BaseItem;
import item.base.BaseWeapon;
import item.usage.AttBuffable;
import item.usage.Healable;

import java.util.ArrayList;

public class Player {

    private final int MAX_HP;
    private final Inventory INVENTORY;
    private String name;
    private int hp;
    private int pos;
    private Helmet helmetSlot;
    private Suit suitSlot;
    private Boots bootsSlot;
    private int attBuffing;
    private int buffRemainingTurn;

    public Player(String name) throws NegativePosException {
        setName(name);
        setPos(0);
        MAX_HP = 20;
        setHp(MAX_HP);
        INVENTORY = new Inventory();
        setAttBuffing(0);
        setBuffRemainingTurn(0);
    }

    public String useWeapon(BaseWeapon item, Player opponent) {
        if (Math.abs(opponent.getPos() - getPos()) <= item.getRange()) {
            int calculatedValue = calculateAtt(item);
            opponent.beingAttack(calculatedValue);
            decreaseWeaponDur(item);
            return getName() + " attacked " + opponent.getName();
        } else {
            return opponent.getName() + " is not in attackable range";
        }
    }

    public void beingAttack(int att) {
        int damage = att - calculateDef();
        if (damage < 0) damage = 0;
        setHp(getHp() - damage);
        decreaseArmorDur();
    }

    public void decreaseArmorDur() {
        if (bootsSlot != null) {
            bootsSlot.setDurability(bootsSlot.getDurability() - 1);
            if (bootsSlot.getDurability() == 0) {
                bootsSlot = null;
            }
        }
        if (suitSlot != null) {
            suitSlot.setDurability(suitSlot.getDurability() - 1);
            if (suitSlot.getDurability() == 0) {
                suitSlot = null;
            }
        }
        if (helmetSlot != null) {
            helmetSlot.setDurability(helmetSlot.getDurability() - 1);
            if (helmetSlot.getDurability() == 0) {
                helmetSlot = null;
            }
        }
    }

    public void decreaseWeaponDur(BaseWeapon item) {
        item.setDurability(item.getDurability() - 1);
        if (item.getDurability() == 0) {
            getInventory().removeItem(item);
        }
    }

    public String useNonWeaponItem(BaseItem item) {
        ArrayList<String> s = new ArrayList<>();
        if (item instanceof BaseArmor) {
            s.add(wear((BaseArmor) item));
        }
        if (item instanceof Healable) {
            s.add(useHeal((Healable) item));
        }
        if (item instanceof AttBuffable) {
            s.add(useBuff((AttBuffable) item));
        }
        getInventory().removeItem(item);
        return (s.isEmpty() ? "Unknown Item" : String.join("\n", s));
    }

    private String useHeal(Healable item) {
        int oldHp = getHp();
        setHp(getHp() + item.getRecoverPoint());
        return (getName() + " +" + (getHp() - oldHp) + " HP");
    }

    private String useBuff(AttBuffable item) {
        setAttBuffing(item.getAttBuff());
        setBuffRemainingTurn(item.getBuffTurn() + 1);
        return (getName() + " +" + item.getAttBuff() + " ATT for next " + item.getBuffTurn() + " turns");
    }

    private String wear(BaseArmor item) {
        if (item instanceof Suit suit) {
            if (getSuitSlot() != null) {
                Suit oldSuit = getSuitSlot();
                getInventory().addItem(oldSuit);
            }
            setSuitSlot(suit);
        } else if (item instanceof Boots boots) {
            if (getBootsSlot() != null) {
                Boots oldBoots = getBootsSlot();
                getInventory().addItem(oldBoots);
            }
            setBootsSlot(boots);
        } else if (item instanceof Helmet helmet) {
            if (getHelmetSlot() != null) {
                Helmet oldHelmet = getHelmetSlot();
                getInventory().addItem(oldHelmet);
            }
            setHelmetSlot(helmet);
        }
        return getName() + " wear " + item.getName();
    }

    public int calculateAtt(BaseWeapon weapon) {
        return weapon.getAtt() + getAttBuffing();
    }

    public int calculateDef() {
        int def = 0;
        if (getSuitSlot() != null) def += getSuitSlot().getDef();
        if (getBootsSlot() != null) def += getBootsSlot().getDef();
        if (getHelmetSlot() != null) def += getHelmetSlot().getDef();
        return def;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
        if (name.isBlank()) {
            this.name = "Steve";
        }
    }

    public int getHp() {
        return hp;
    }

    public void setHp(int hp) {
        if (hp < 0) {
            this.hp = 0;
        } else this.hp = Math.min(hp, MAX_HP);
    }

    public int getMaxHp() {
        return MAX_HP;
    }

    public int getPos() {
        return pos;
    }

    public void setPos(int pos) throws NegativePosException {
        if (pos < 0) {
            throw new NegativePosException();
        }
        this.pos = pos;
    }

    public Helmet getHelmetSlot() {
        return helmetSlot;
    }

    public void setHelmetSlot(Helmet helmetSlot) {
        this.helmetSlot = helmetSlot;
    }

    public Suit getSuitSlot() {
        return suitSlot;
    }

    public void setSuitSlot(Suit suitSlot) {
        this.suitSlot = suitSlot;
    }

    public Boots getBootsSlot() {
        return bootsSlot;
    }

    public void setBootsSlot(Boots bootsSlot) {
        this.bootsSlot = bootsSlot;
    }

    public int getAttBuffing() {
        return attBuffing;
    }

    public void setAttBuffing(int attBuffing) {
        this.attBuffing = Math.max(0, attBuffing);
    }

    public int getBuffRemainingTurn() {
        return buffRemainingTurn;
    }

    public void setBuffRemainingTurn(int turn) {
        this.buffRemainingTurn = Math.max(0, turn);
        if (getBuffRemainingTurn() == 0) {
            setAttBuffing(0);
        }
    }

    public Inventory getInventory() {
        return INVENTORY;
    }

    public void printEquipment() {
        System.out.println("[Total DEF : " + calculateDef() + "]");
        System.out.println("Helmet : " + ((getHelmetSlot() != null) ? getHelmetSlot().getDurability() + " uses left" : "-"));
        System.out.println("Suit   : " + ((getSuitSlot() != null) ? "Lv." + getSuitSlot().getLevel() + ", " + getSuitSlot().getDurability() + " uses left" : "-"));
        System.out.println("Boots  : " + ((getBootsSlot() != null) ? getBootsSlot().getDurability() + " uses left" : "-"));
    }

}
