//This lab is too long T_T
//Now, I know the pain of generating testcases for others.
//However, thank you for this lab and please give me full score 🥺🥺🥺🥺

//I do not have any specific TA that I like as all TAs are very helpful to me.
//Thank you for helping us out.
//Hope you have a good day!

package grader.student;

import java.util.ArrayList;
import java.util.List;

import logic.ghost.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import logic.actor.Actor;
import logic.actor.GhostDoctor;
import logic.actor.Villager;
import logic.game.GameController;
import logic.game.GameIO;
import logic.item.Item;
import logic.item.Leklai;

import static org.junit.jupiter.api.Assertions.*;

class GameControllerTest {
    @Test
    void testPlayNotDestroyedGhost() {
        Actor actor = new Villager();
        
        Ghost g1 = new PooYaGhost(8);
        Ghost g2 = new GaGhost();
        Ghost g3 = new PryGhost();
        
        GameController.getInstance().getGhosts().clear();
        GameController.getInstance().getItems().clear();
        GameController.getInstance().addNewGhost(g1);
        GameController.getInstance().addNewGhost(g2);
        GameController.getInstance().addNewGhost(g3);
        
        GameController.getInstance().play(actor);
        
        assertEquals(g1, GameController.getInstance().getGhosts().get(0));
        assertEquals(3, GameController.getInstance().getGhosts().size());
    }
    
    @Test
    void testPlayDestroyedGhost() {
    	Actor actor = new GhostDoctor();
        
        Ghost g1,g2,g3;
        g1 = new GaGhost(1);
        g2 = new PooYaGhost(1);
        g3 = new MaBongGhost(1);

        GameController.getInstance().getGhosts().clear();

        GameController.getInstance().getGhosts().add(g1);
        GameController.getInstance().getGhosts().add(g2);
        GameController.getInstance().getGhosts().add(g3);
        
        GameController.getInstance().play(actor);

        assertEquals(g2, GameController.getInstance().getGhosts().get(0));
        assertEquals(3, GameController.getInstance().getGhosts().size());
    }
    
    @Test
    void testPlayWithItem() {
    	Actor actor = new Villager();
        Item item = new Leklai();
        
        GameController.getInstance().getGhosts().clear();
        Ghost g1 = new GaGhost();
        Ghost g2 = new PryGhost();
        Ghost g3 = new PooYaGhost(10);

        GameController.getInstance().getGhosts().clear();
        GameController.getInstance().getGhosts().add(g1);
        GameController.getInstance().getGhosts().add(g2);
        GameController.getInstance().getGhosts().add(g3);

        GameController.getInstance().getItems().add(item);

        GameController.getInstance().play(actor);

        assertEquals(0, g1.getHp());
        assertEquals(0, g2.getHp());
        assertEquals(10, g3.getHp());


    }
    @Test
    void testIsGameOver() {
        //actors.isEmpty() || getHp() <= 0
        GameController.getInstance().setHp(100);
        assertFalse(GameController.getInstance().isGameOver());
        GameController.getInstance().setHp(0);
        assertTrue(GameController.getInstance().isGameOver());
        GameController.getInstance().setHp(-100);
        assertTrue(GameController.getInstance().isGameOver());
        GameController g = new GameController();
        assertFalse(g.isGameOver());

    }

}