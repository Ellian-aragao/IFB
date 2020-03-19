package trabalho2;

import javax.swing.JOptionPane;

public class CadastraFuncionarios {
    
    public static void main(String[] args) {
        Integer matricula = Integer.parseInt(JOptionPane.showInputDialog(null, "entre com a matrícula", "CADASTRAMENTO", 3));
        String nome = JOptionPane.showInputDialog(null, "nome: ", "CADASTRAMENTO", 3);
        String dataDeNascimento = JOptionPane.showInputDialog(null, "data de nascimento", "CADASTRAMENTO", 3);
        String cargo = JOptionPane.showInputDialog(null, "cargo ", "CADASTRAMENTO", 3);
        
        Funcionario func = new Funcionario(matricula, nome, dataDeNascimento, cargo);
        System.out.println(func.toString());
    }
}
