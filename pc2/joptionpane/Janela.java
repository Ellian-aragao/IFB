package joptionpane;

import javax.swing.JOptionPane;

public class Janela {
    public static void main(String[] args) {
        String matricula = JOptionPane.showInputDialog(null, "entre com a matrícula", "CADASTRAMENTO", 3);
        JOptionPane.showMessageDialog(null, matricula);
    }
}