package src.obj.area;

import java.util.ArrayList;
import src.obj.monster.Monster;

public class Room {
    public record Area(double l, double w) {}

    private Area area;
    private double[] exitDoor;
    private ArrayList<Monster> monsters;
}
