using LibGit2Sharp;

public class Mini_4
{
    public static void start()
    {
        Console.Write("Way to repository: ");
        var repo = new Repository(Console.ReadLine());
        var AllBranches = repo.Branches.ToList();
        Console.WriteLine("Select the desired branch");
        for (int i = 0; i < AllBranches.Count; i++) {
            Console.WriteLine("[" + i + "] branch name: " + AllBranches[i]);
        }
        Console.Write("Number: ");
        var SelecteвBranch = AllBranches[Convert.ToInt32(Console.ReadLine())];
        var Commits = SelecteвBranch.Commits.ToList();
        Branch currentBranch = Commands.Checkout(repo, SelecteвBranch);
        Console.WriteLine("Choose the number of a \"good\" commit");
        for (int i = 0; i < Commits.Count; i++)
        {
            Console.WriteLine("[" + (Commits.Count - i - 1) + "] commit name: " + Commits[i].MessageShort);
        }
        Console.Write("Choose the number of a \"good\" commit: ");
        int good = Commits.Count - Convert.ToInt32(Console.ReadLine());
        int bad = 1;
        Console.Write("Choose the number of a \"bad\" commit: ");
        int shift  = Commits.Count - Convert.ToInt32(Console.ReadLine()) - 1;
        int middle;

        for (int i = 0; ; i++)
        {
            middle = (good + bad) / 2;
            if (good - bad <= 1)
            {
                Console.WriteLine("bug in: " + Commits[bad - 1 + shift].MessageShort);
                break;
            }
            Commands.Checkout(repo, Commits[middle - 1 + shift]);
            Console.WriteLine("Check commit : " + Commits[middle - 1 + shift].MessageShort);
            bool GoodBad = Console.ReadLine() == "good" ? true : false;
            if (GoodBad) good -= (good - bad + 1) / 2;
            else bad += (good - bad) / 2;

        }
    }

    

}
