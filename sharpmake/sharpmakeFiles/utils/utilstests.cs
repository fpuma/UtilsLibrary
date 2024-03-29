namespace Puma
{
    [Sharpmake.Generate]
    class UtilsTests : Puma.Common.IMyApplication
    {
        public UtilsTests()
            : base("UtilsTests", @"utilstests")
        { }

        public override void ConfigureAll(Configuration conf, Sharpmake.Target target)
        {
            base.ConfigureAll(conf, target);

            conf.AddPrivateDependency<Puma.Utils>(target);
            conf.AddPrivateDependency<Puma.GoogleTest>(target);

            conf.Options.Add(Sharpmake.Options.Vc.General.TreatWarningsAsErrors.Enable);

            if (target.Optimization != Sharpmake.Optimization.Debug)
            {
                conf.IsExcludedFromBuild = true;
            }
        }
    }
}