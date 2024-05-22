/*

  Created by David Spooner

 */


#if false
extension Int : Parsable {
  public static var productionRule : ProductionRule<Self> {
    .init(pattern: "[0-9]+") { string in
      .init(string)!
    }
  }
}
#endif
